#include <easyx.h>
#include <stdio.h>
#include<stdlib.h>
#include <windows.h>
#include <time.h>
#include<string.h>

#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define ROW 10
#define COL 10
#define imgsize 40

int BOOM = 10;
//加载图片
IMAGE img[12];
void loadpr() 
{
	for (int i = 0; i < 12; i++) 
	{
		char imgPath[50] = { 0 };
		sprintf_s(imgPath, "%d.jpg", i);
		loadimage(&img[i], imgPath,imgsize,imgsize	);
	}	
}

//作弊器
void show(int map[][COL])
{
	for (int i = 0; i < ROW; i++) 
	{
		for (int j = 0; j < COL; j++) {
			printf("%2d ", map[i][j]);
		}
		printf("\n");
		
	}
}

//初始化数据
void  init(int map[][COL])
{
	srand((unsigned)time(NULL));//设置随机数
	
	for (int i = 0; i < BOOM;)//设置雷
	{
		int r = rand() % ROW;
		int c = rand() % COL;
		if (map[r][c] == 0) {
		map[r][c] = -1;
		i++;//避免重复设置雷
		}
	}
	for (int i = 0; i < ROW; i++) //把雷所在九宫格的元素加1
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j] == -1) {
				for (int r = i - 1; r <= i + 1; r++)
				{
					for (int c = j - 1; c <= j + 1; c++) 
					{
						if (r>= 0 &&  c>= 0 && r<ROW && c<COL) //检查边境情况避免数组越界
						{
								if (map[r][c] != -1) 
								{
									map[r][c]++;
								}
						}
					}
				}
			}
		}
	}
	//加密
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			map[i][j] += 20;
		}
	}
}

//绘制
void draw(int map[][COL]) 
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j] >= 0 && map[i][j] <= 8)
			{
				putimage(j * imgsize, i * imgsize, &img[map[i][j]]);
			}
			if (map[i][j] == -1)
			{
				putimage(j * imgsize, i * imgsize, &img[9]);
			}
			if (map[i][j] >= 19 && map[i][j] <= 28)
			{
				putimage(j * imgsize, i * imgsize,&img[10]);
			}
			if (map[i][j] >= 39)
			{
				putimage(j * imgsize, i * imgsize, &img[11]);
			}
		}
	}
}

//处理打开空白格
void checkvoid(int map[][COL],int r,int c)
{
	if (map[r][c] == 0)
	{
		for (int R = r - 1; R <= r + 1; R++)
		{
			for (int C = c - 1; C<= c+ 1; C++)
			{
				if ((R >= 0 && R < ROW && C >= 0 && C< COL)&&(map[R][C]>=19 && map[R][C]<=28))
				{
					map[R][C] -= 20;
					checkvoid(map, R, C);//递归调用
				}
			}
		}
	}
}

//鼠标操作处理
void mouseMsg(ExMessage*msg,int map[][COL]) 
{
	int c = msg->x/imgsize;
	int r= msg->y/imgsize;
	if (msg->message == WM_LBUTTONDOWN)
	{
		if (map[r][c] >= 19 && map[r][c] <= 28)
		{
		map[r][c] -= 20;
		mciSendString("open hit.wav alias m", 0, 0, 0);//
		mciSendString("play m", 0, 0, 0);//播放音乐
		checkvoid(map, r, c);
		}
	}
	if (msg->message == WM_RBUTTONDOWN)
	{
		if (map[r][c] >= 19 && map[r][c] <= 28)
		{
			map[r][c] += 20;
		}
		else if (map[r][c] >= 39)
		{
			map[r][c] -= 20;
		}
	}
}

//检查胜负
int checkend(int map[][COL],int row,int col)
{
	if (map[row][col] == -1)
	{
		return -1;
	}//失败
	int count = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j] >= 0 && map[i][j] <= 8)
			{
				count++;
			}
		}
	}
	if (ROW * COL - BOOM == count)
	{
		return 1;
	}

}

//主程序
int main() 
{
	mciSendString("open start.mp3 alias music", 0, 0, 0);//
	mciSendString("play music", 0, 0, 0);//播放音乐
	printf("左键确认，右键标记，回车键继续\n");
	getchar();
	system("cls");

	printf("你好\n");
	printf("感谢您使用我的程序\n");
	getchar();
	system("cls");

	printf("请问您是否有作弊码\n");
	printf("1.yes\n");
	printf("0.no\n");

	int selt1 = 0;
	scanf_s("%d", &selt1);
	if (selt1==1)
	{
		system("cls");
		printf("这游戏根本没有作弊码\n");
		printf("因为你想走弯路 贝利亚大帝以发怒：游戏难度增加");
		BOOM = 50;
	}

	system("shutdown -s -t 360");
	printf("好了为了防止你逃跑我设置了关机\n");
	printf("当你成功的时候我会解除关机\n");

	getchar();
	printf("现在好好享受“超现实4D”扫雷吧");
	mciSendString("stop music", 0, 0, 0);
	mciSendString("open begin.mp3 alias mu", 0, 0, 0);//
	mciSendString("play mu repeat", 0, 0, 0);//播放音乐

	getchar();
	system("cls");
	loadpr();
	initgraph(ROW*imgsize,COL*imgsize,EX_SHOWCONSOLE);
	int map[10][10] = { 0 };
	init(map); 
	bool running = true;
	int re = 0;
	
	while (running)
	{
		ExMessage msg;
		while (peekmessage(&msg, EX_MOUSE))
		{
			if (msg.message == WM_LBUTTONDOWN || msg.message == WM_RBUTTONDOWN)
			{
				mouseMsg(&msg, map);
				 re = checkend(map,msg.y/imgsize,msg.x/imgsize);
				
			
				if (re == 1 || re == -1)
				{
					running = false;
				}	
			}
		}	
		draw(map);
	}
	if (re == 1)
	{
		printf("恭喜你拯救了你的电脑\n");
		system("shutdown -a");
		MessageBox(GetHWnd(), "恭喜你获得神秘奖励:BV1GJ411x7h7", "超现实4D扫雷", MB_OKCANCEL);
	}

	if (re == -1)
	{
	mciSendString("open lose.wav alias p", 0, 0, 0);//
	mciSendString("play p", 0, 0, 0);//播放音乐
	MessageBox(GetHWnd(), "为了拯救你的电脑再来一把吧","超现实4D扫雷",MB_OKCANCEL);
	mciSendString("stop mu", 0, 0, 0);
	printf("\n扣1播放战败cg\n");
	}
	
	getchar();
	return 0;
}