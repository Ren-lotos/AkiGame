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
void startPage();//开始界面
void talePage();//导入界面
void endPage(pl* mPlayer);//结束界面
//void drawPic();
void initGame(pl* mPlayer);//初始化游戏
int battlePage(pl* mPlayer);
void delay(int t);//延时
void SetPos(short x,short y);//设置位置
void HideCursor();//隐藏光标
bool SetConsoleColor(WORD wAttributes);
void day1(pl* mPlayer);//第一天
void day2(pl* mPlayer);//第二天
void day3(pl* mPlayer);//第三天
void game(pl* mPlayer);//拓展模块

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
	cout << "||你是一名小说家，由于缺乏创作灵感，决定外出取材"<< endl;
	delay(2.5);
	SetPos(70,7);
	YELLOW;
	cout << "||你将前往一个偏远小镇，你的据点是镇上的旅馆，你将在小镇度过3天"<< endl;
	delay(2.5);
	SetPos(70,9);
	GREEN;
	cout << "[希望多多少少能有些收获吧]"<< endl;
	delay(2.5);
	SetPos(70,11);
	YELLOW;
	cout << "||计时结束后将开始你在小镇上的第一天"<< endl;
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
			cout << "那么开始吧";
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
	cout << "||你抵达了旅馆，旅馆的环境和镇上的风景让你很满意"<< endl;
	delay(2.5);
	SetPos(70,7);
	YELLOW;
	cout << "||你决定"<< endl;
	SetPos(70,9);
	YELLOW;
	cout << "||1.探索旅馆"<< endl;
	SetPos(70,11);
	YELLOW;
	cout << "||2.出门看看"<< endl;
	SetPos(70,13);
	YELLOW;
	cout << "||3.呆在自己的房间里构思小说"<< endl;
	SetPos(70,14);
	scanf("%d",&t);
	system("cls");
	switch (t)
			{
			case 1:
				SetPos(60,5);
				YELLOW;
				cout << "||旅馆有一个奇怪的房间，房间里堆满了娃娃"<< endl;
				delay(2.5);
				SetPos(60,7);
				YELLOW;
				cout << "||晚上，你在好奇心的驱使下，走进了这个奇怪的房间。"<< endl;
				delay(2.5);
				SetPos(60,9);
				YELLOW;
				cout << "||周围静悄悄的，你能听到自己的呼吸和心跳声"<< endl;
				delay(2.5);
				SetPos(60,11);
				YELLOW;
				cout << "||当你准备离开房间时，你遇见了一个不可思议的黑发少女，不知何时出现在你身后"<< endl;
				delay(2.5);
				SetPos(60,13);
				BLUE;
				cout << "少女递出一个万华镜「要看一下这个吗？要看一下你所窥视不到的世界吗？]"<< endl;
				delay(2.5);
				SetPos(60,15);
				YELLOW;
				cout << "||你也曾有过一个万华镜，少女的万华镜让你想起了过去，你使用万华镜，窥探到了另一个世界(理智-5)"<< endl;
				delay(2.5);
				mPlayer->san -= 5;
				mPlayer->see += 1;
				break;
			
			case 2:
				SetPos(60,5);
				YELLOW;
				cout << "||你遇到了一个自称黑法老的怪人"<< endl;
				delay(2.5);
				SetPos(60,7);
				YELLOW;
				cout << "||黑法老告诉你，她有一个奇物商店，希望你能关照一下她的生意"<< endl;
				delay(2.5);
				SetPos(60,9);
				YELLOW;
				cout << "||你告诉她，自己会考虑的"<< endl;
				delay(2.5);
				break;

			default:
				SetPos(60,5);
				YELLOW;
				cout << "||今天什么也没发生"<< endl;
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
	cout << "||第二天"<< endl;
	delay(2.5);
	SetPos(70,7);
	YELLOW;
	cout << "||你决定"<< endl;
	SetPos(70,9);
	YELLOW;
	cout << "||1.在旅馆里走走"<< endl;
	SetPos(70,11);
	YELLOW;
	cout << "||2.出门采风"<< endl;
	SetPos(70,13);
	YELLOW;
	cout << "||3.呆在自己的房间里构思小说"<< endl;
	SetPos(70,14);
	scanf("%d",&t);
	system("cls");
	switch (t)
			{
			case 1:
				SetPos(60,5);
				YELLOW;
				cout << "||你在旅馆里看见了拿着万华镜的黑发少女"<< endl;
				delay(2.5);
				SetPos(60,7);
				YELLOW;
				cout << "||少女也看见了"<< endl;
				delay(2.5);
				SetPos(60,9);
				BLUE;
				cout << "[你是为了万华镜而来的吗？]"<< endl;
				delay(2.5);
				SetPos(60,11);
				YELLOW;
				cout << "||你点点头"<< endl;
				delay(2.5);
				SetPos(60,13);
				YELLOW;
				cout << "||你从万华镜中看见了世界，你沉醉其中"<< endl;
				delay(2.5);
				mPlayer->san -= 5;
				mPlayer->see += 1;
				if (mPlayer->see >= 2)
				{
					SetPos(60,15);
					BLUE;
					cout << "[你不应该再来了]"<< endl;
					delay(2.5);
				}
				
				break;
			
			case 2:
				SetPos(60,5);
				BLUE;
				cout << "[要试试奇物商店吗？]"<< endl;
				delay(2.5);
				SetPos(60,7);
				YELLOW;
				cout << "||你觉得可以尝试一下"<< endl;
				delay(2.5);
				game(mPlayer);
				break;

			default:
				SetPos(60,5);
				YELLOW;
				cout << "||今天什么也没发生"<< endl;
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
	cout << "||旅途的最后一天"<< endl;
	delay(2.5);
	SetPos(70,7);
	YELLOW;
	cout << "||你决定"<< endl;
	SetPos(70,9);
	YELLOW;
	cout << "||1.在旅馆走走就好"<< endl;
	SetPos(70,11);
	YELLOW;
	cout << "||2.出门拍照留念"<< endl;
	SetPos(70,13);
	YELLOW;
	cout << "||3.呆在自己的房间里构思小说"<< endl;
	SetPos(70,14);
	scanf("%d",&t);
	system("cls");
	switch (t)
			{
			case 1:
				SetPos(60,5);
				YELLOW;
				cout << "||你在旅馆里看见了拿着万华镜的黑发少女"<< endl;
				delay(2.5);
				SetPos(60,7);
				YELLOW;
				cout << "||少女也看见了"<< endl;
				delay(2.5);
				SetPos(60,9);
				BLUE;
				cout << "[你是为了万华镜而来的吗？]"<< endl;
				delay(2.5);
				SetPos(60,11);
				YELLOW;
				cout << "||你点点头"<< endl;
				delay(2.5);
				SetPos(60,13);
				YELLOW;
				cout << "||你从万华镜中看见了世界，你沉醉其中"<< endl;
				delay(2.5);
				mPlayer->san -= 5;
				mPlayer->see += 1;
				if (mPlayer->see >= 3)
				{
					SetPos(60,15);
					BLUE;
					cout << "[你将会失去灵魂]"<< endl;
					delay(2.5);
				}
				break;
			
			case 2:
				battlePage(mPlayer);
				break;

			default:
				SetPos(60,5);
				YELLOW;
				cout << "||今天什么也没发生"<< endl;
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
		cout << "||你成为了万华镜的一部分，在另一个世界里，你看上去很幸福"<< endl;
		delay(2.5);
	}
	else if(mPlayer->see != 0 && mPlayer->flag == 1)
	{
		SetPos(60,5);
		GREEN;
		cout << "||万华镜给了你充足的灵感，你写下了《瓦尔哈拉之夜》。但是从那此旅行后，你总是有一种被注视的感觉"<< endl;
		delay(2.5);
	}
	else if(mPlayer->see != 0 && mPlayer->flag == 0)
	{
		SetPos(60,5);
		GREEN;
		cout << "||万华镜给了你充足的灵感，你写下了《瓦尔哈拉之夜》。这段旅行成了你人生精彩的一页"<< endl;
		delay(2.5);
	}
	else if(mPlayer->see == 0 && mPlayer->flag == 1)
	{
		SetPos(60,5);
		GREEN;
		cout << "||你的人生在某人的恶作剧下天翻地覆"<< endl;
		delay(2.5);
	}
	else
	{
		SetPos(60,5);
		GREEN;
		cout << "||你觉得这次旅行自己似乎忘记了什么，平静的生活仍在继续"<< endl;
		delay(2.5);
	}
}

int battlePage(pl* mPlayer)
{
	SetPos(60,5);
	YELLOW;
	cout << "||你的相机拍到了不该拍到的东西。不可名状的恐惧席卷了你"<< endl;
	delay(2.5);
	if (mPlayer->see != 0)
	{
		SetPos(60,7);
		YELLOW;
		cout << "||你失去意识前好像看到了一缕黑发"<< endl;
		delay(2.5);
	}
	else
	{
		SetPos(60,7);
		YELLOW;
		cout << "||你失去意识"<< endl;
		delay(2.5);
		mPlayer->san -= 20;
	}
	
}

void game(pl* mPlayer)
{
	//小游戏本版本暂不添加
	mPlayer->san = 70;
	mPlayer->flag = 1;
}


