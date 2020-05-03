//#include "windef.h"
//#include "mmsystem.h"
#include "windows.h"
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <conio.h>
//#include <stdbool.h>
//#pragma comment(lib,"winmm.lib")//bgm 
#define BLUE SetConsoleColor(FOREGROUND_BLUE|FOREGROUND_INTENSITY)
#define YELLOW SetConsoleColor(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY)
#define GREEN SetConsoleColor(FOREGROUND_GREEN|FOREGROUND_INTENSITY)

using namespace std;

typedef struct player
{
	int hp;
	int mp;
	int san;
	int see;
	int flag;

}pl;

HWND hwnd = GetForegroundWindow();
void startPage();//��ʼ����
void talePage();//�������
void endPage(pl* mPlayer);//��������
//void drawPic();
void initGame(pl* mPlayer);//��ʼ����Ϸ
int battlePage(pl* mPlayer);
void delay(int t);//��ʱ
void SetPos(short x,short y);//����λ��
void HideCursor();//���ع��
bool SetConsoleColor(WORD wAttributes);
void day1(pl* mPlayer);//��һ��
void day2(pl* mPlayer);//�ڶ���
void day3(pl* mPlayer);//������
void game(pl* mPlayer);//��չģ��

int main()
{
	SetConsoleTitle("Valhalla");
	//PlaySound(TEXT("1.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
	startPage();
	int day = 3;
	int t = 1;
	char c;
	cin >> c;
	if(c == 'Y' || c == 'y')
	{
		pl player1;
		initGame(&player1);
		talePage();
		while (day--)
		{
			switch (t)
			{
			case 1:
				day1(&player1);
				break;
			
			case 2:
				day2(&player1);
				break;

			case 3:
				day3(&player1);
				break;	

			default:
				break;
			}
			t++;
		}
		endPage(&player1);
		return 0;
	}
	else
	{
		return 0;
	}
}

void delay(int t)
{
	time_t start_time,cur_time;
	time(&start_time);
	do{
		time(&cur_time);
	}while(cur_time - start_time < t);
}

void SetPos(short x,short y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x , y};
	SetConsoleCursorPosition(hOut, pos);
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

bool SetConsoleColor(WORD wAttributes)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
	{
		return FALSE;
	}
	return SetConsoleTextAttribute(hConsole,wAttributes);
}
//welcomePage
void startPage()
{
	HANDLE outPut;
	outPut = GetStdHandle(STD_OUTPUT_HANDLE);
	HideCursor();
	SetPos(70, 10);
	BLUE;
	cout << " Welcome to Valhalla";
	SetPos(70,15);
	BLUE;
	cout << "Y:start       N:end ";
	SetPos(70, 25);
	BLUE;
	cout << "Please input Y or N : ";

}
//Game background story
void talePage()
{
	system("cls");
	HANDLE outPut;
	outPut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetPos(70,5);
	YELLOW;
	cout << "||����һ��С˵�ң�����ȱ��������У��������ȡ��"<< endl;
	delay(2.5);
	SetPos(70,7);
	YELLOW;
	cout << "||�㽫ǰ��һ��ƫԶС����ľݵ������ϵ��ùݣ��㽫��С��ȹ�3��"<< endl;
	delay(2.5);
	SetPos(70,9);
	GREEN;
	cout << "[ϣ�������������Щ�ջ��]"<< endl;
	delay(2.5);
	SetPos(70,11);
	YELLOW;
	cout << "||��ʱ�����󽫿�ʼ����С���ϵĵ�һ��"<< endl;
	delay(2.5);
	SetPos(70,13);
	for(int i = 5; i >= 0; i--)
	{
		if (i)
		{
			printf("%d\b", i);
		}
		else
		{
			cout << "��ô��ʼ��";
		}
		delay(1);
	}
}

void initGame(pl* mPlayer)
{
	mPlayer->hp = 100;
	mPlayer->mp = 100;
	mPlayer->san = 70;
	mPlayer->see = 0;
	mPlayer->flag = 0;
}

void day1(pl* mPlayer)
{
	system("cls");
	HANDLE outPut;
	outPut = GetStdHandle(STD_OUTPUT_HANDLE);
	int t;
	SetPos(70,5);
	YELLOW;
	cout << "||��ִ����ùݣ��ùݵĻ��������ϵķ羰���������"<< endl;
	delay(2.5);
	SetPos(70,7);
	YELLOW;
	cout << "||�����"<< endl;
	SetPos(70,9);
	YELLOW;
	cout << "||1.̽���ù�"<< endl;
	SetPos(70,11);
	YELLOW;
	cout << "||2.���ſ���"<< endl;
	SetPos(70,13);
	YELLOW;
	cout << "||3.�����Լ��ķ����ﹹ˼С˵"<< endl;
	SetPos(70,14);
	scanf("%d",&t);
	system("cls");
	switch (t)
			{
			case 1:
				SetPos(60,5);
				YELLOW;
				cout << "||�ù���һ����ֵķ��䣬���������������"<< endl;
				delay(2.5);
				SetPos(60,7);
				YELLOW;
				cout << "||���ϣ����ں����ĵ���ʹ�£��߽��������ֵķ��䡣"<< endl;
				delay(2.5);
				SetPos(60,9);
				YELLOW;
				cout << "||��Χ�����ĵģ����������Լ��ĺ�����������"<< endl;
				delay(2.5);
				SetPos(60,11);
				YELLOW;
				cout << "||����׼���뿪����ʱ����������һ������˼��ĺڷ���Ů����֪��ʱ�����������"<< endl;
				delay(2.5);
				SetPos(60,13);
				BLUE;
				cout << "��Ů�ݳ�һ���򻪾���Ҫ��һ�������Ҫ��һ���������Ӳ�����������]"<< endl;
				delay(2.5);
				SetPos(60,15);
				YELLOW;
				cout << "||��Ҳ���й�һ���򻪾�����Ů���򻪾����������˹�ȥ����ʹ���򻪾�����̽������һ������(����-5)"<< endl;
				delay(2.5);
				mPlayer->san -= 5;
				mPlayer->see += 1;
				break;
			
			case 2:
				SetPos(60,5);
				YELLOW;
				cout << "||��������һ���Գƺڷ��ϵĹ���"<< endl;
				delay(2.5);
				SetPos(60,7);
				YELLOW;
				cout << "||�ڷ��ϸ����㣬����һ�������̵꣬ϣ�����ܹ���һ����������"<< endl;
				delay(2.5);
				SetPos(60,9);
				YELLOW;
				cout << "||����������Լ��ῼ�ǵ�"<< endl;
				delay(2.5);
				break;

			default:
				SetPos(60,5);
				YELLOW;
				cout << "||����ʲôҲû����"<< endl;
				delay(2.5);
				break;
			}
}

void day2(pl* mPlayer)
{
	system("cls");
	HANDLE outPut;
	outPut = GetStdHandle(STD_OUTPUT_HANDLE);
	int t;
	SetPos(70,5);
	YELLOW;
	cout << "||�ڶ���"<< endl;
	delay(2.5);
	SetPos(70,7);
	YELLOW;
	cout << "||�����"<< endl;
	SetPos(70,9);
	YELLOW;
	cout << "||1.���ù�������"<< endl;
	SetPos(70,11);
	YELLOW;
	cout << "||2.���Ųɷ�"<< endl;
	SetPos(70,13);
	YELLOW;
	cout << "||3.�����Լ��ķ����ﹹ˼С˵"<< endl;
	SetPos(70,14);
	scanf("%d",&t);
	system("cls");
	switch (t)
			{
			case 1:
				SetPos(60,5);
				YELLOW;
				cout << "||�����ù��￴���������򻪾��ĺڷ���Ů"<< endl;
				delay(2.5);
				SetPos(60,7);
				YELLOW;
				cout << "||��ŮҲ������"<< endl;
				delay(2.5);
				SetPos(60,9);
				BLUE;
				cout << "[����Ϊ���򻪾���������]"<< endl;
				delay(2.5);
				SetPos(60,11);
				YELLOW;
				cout << "||����ͷ"<< endl;
				delay(2.5);
				SetPos(60,13);
				YELLOW;
				cout << "||����򻪾��п��������磬���������"<< endl;
				delay(2.5);
				mPlayer->san -= 5;
				mPlayer->see += 1;
				if (mPlayer->see >= 2)
				{
					SetPos(60,15);
					BLUE;
					cout << "[�㲻Ӧ��������]"<< endl;
					delay(2.5);
				}
				
				break;
			
			case 2:
				SetPos(60,5);
				BLUE;
				cout << "[Ҫ���������̵���]"<< endl;
				delay(2.5);
				SetPos(60,7);
				YELLOW;
				cout << "||����ÿ��Գ���һ��"<< endl;
				delay(2.5);
				game(mPlayer);
				break;

			default:
				SetPos(60,5);
				YELLOW;
				cout << "||����ʲôҲû����"<< endl;
				delay(2.5);
				break;
			}
}

void day3(pl* mPlayer)
{
	system("cls");
	HANDLE outPut;
	outPut = GetStdHandle(STD_OUTPUT_HANDLE);
	int t;
	SetPos(70,5);
	YELLOW;
	cout << "||��;�����һ��"<< endl;
	delay(2.5);
	SetPos(70,7);
	YELLOW;
	cout << "||�����"<< endl;
	SetPos(70,9);
	YELLOW;
	cout << "||1.���ù����߾ͺ�"<< endl;
	SetPos(70,11);
	YELLOW;
	cout << "||2.������������"<< endl;
	SetPos(70,13);
	YELLOW;
	cout << "||3.�����Լ��ķ����ﹹ˼С˵"<< endl;
	SetPos(70,14);
	scanf("%d",&t);
	system("cls");
	switch (t)
			{
			case 1:
				SetPos(60,5);
				YELLOW;
				cout << "||�����ù��￴���������򻪾��ĺڷ���Ů"<< endl;
				delay(2.5);
				SetPos(60,7);
				YELLOW;
				cout << "||��ŮҲ������"<< endl;
				delay(2.5);
				SetPos(60,9);
				BLUE;
				cout << "[����Ϊ���򻪾���������]"<< endl;
				delay(2.5);
				SetPos(60,11);
				YELLOW;
				cout << "||����ͷ"<< endl;
				delay(2.5);
				SetPos(60,13);
				YELLOW;
				cout << "||����򻪾��п��������磬���������"<< endl;
				delay(2.5);
				mPlayer->san -= 5;
				mPlayer->see += 1;
				if (mPlayer->see >= 3)
				{
					SetPos(60,15);
					BLUE;
					cout << "[�㽫��ʧȥ���]"<< endl;
					delay(2.5);
				}
				break;
			
			case 2:
				battlePage(mPlayer);
				break;

			default:
				SetPos(60,5);
				YELLOW;
				cout << "||����ʲôҲû����"<< endl;
				delay(2.5);
				break;
			}
}

void endPage(pl* mPlayer)
{
	system("cls");
	HANDLE outPut;
	outPut = GetStdHandle(STD_OUTPUT_HANDLE);
	if(mPlayer->see == 3)
	{
		SetPos(60,5);
		GREEN;
		cout << "||���Ϊ���򻪾���һ���֣�����һ��������㿴��ȥ���Ҹ�"<< endl;
		delay(2.5);
	}
	else if(mPlayer->see != 0 && mPlayer->flag == 1)
	{
		SetPos(60,5);
		GREEN;
		cout << "||�򻪾�������������У���д���ˡ��߶�����֮ҹ�������Ǵ��Ǵ����к���������һ�ֱ�ע�ӵĸо�"<< endl;
		delay(2.5);
	}
	else if(mPlayer->see != 0 && mPlayer->flag == 0)
	{
		SetPos(60,5);
		GREEN;
		cout << "||�򻪾�������������У���д���ˡ��߶�����֮ҹ����������г������������ʵ�һҳ"<< endl;
		delay(2.5);
	}
	else if(mPlayer->see == 0 && mPlayer->flag == 1)
	{
		SetPos(60,5);
		GREEN;
		cout << "||���������ĳ�˵Ķ��������췭�ظ�"<< endl;
		delay(2.5);
	}
	else
	{
		SetPos(60,5);
		GREEN;
		cout << "||�������������Լ��ƺ�������ʲô��ƽ�����������ڼ���"<< endl;
		delay(2.5);
	}
}

int battlePage(pl* mPlayer)
{
	SetPos(60,5);
	YELLOW;
	cout << "||�������ĵ��˲����ĵ��Ķ�����������״�Ŀ־�ϯ������"<< endl;
	delay(2.5);
	if (mPlayer->see != 0)
	{
		SetPos(60,7);
		YELLOW;
		cout << "||��ʧȥ��ʶǰ���񿴵���һ�ƺڷ�"<< endl;
		delay(2.5);
	}
	else
	{
		SetPos(60,7);
		YELLOW;
		cout << "||��ʧȥ��ʶ"<< endl;
		delay(2.5);
		mPlayer->san -= 20;
	}
	
}

void game(pl* mPlayer)
{
	//С��Ϸ���汾�ݲ����
	mPlayer->san = 70;
	mPlayer->flag = 1;
}


