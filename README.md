# 《超现实4D扫雷》项目介绍

# 必读：温馨提示！！！！

本项目含有定时关机程序你可以通过

win+r输入cmd，cmd调出后输入shutdown -a来解除

或者通关游戏来解除

# **项目简介**

## 1.操作介绍

回车键：用来确认

鼠标左键：扫开一个格子

鼠标右键：标记一个格子

## 2.胜负判断

胜利：打开所有非雷格

失败：打开雷格

## 3.游戏特色

游戏进入时会给电脑下一个定时关机指令

用来模拟排雷时的紧张感

# 外部库说明

## 1.<easyx.h>

图形库实现界面的绘制

## 2 <windows.h>

主要使用其中的system函数来调用cmd来实现游戏特色

## 3.<time.h>

用来给随机数函数rand赋予种子

## 4.<mmsystem.h>

实现对音乐的播放

# 难点与解决方案

## 1.如何判断一个格子是否打开

解决方案：先对随机生成完的二维数组加上某个数字，当点击后在减去这个数组

代码如下

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
			map[i][j] += 20;//密钥是20
		}
	}
`}`

`//绘制`
`void draw(int map[][COL])` 
`{`
	`for (int i = 0; i < ROW; i++)`
	`{`
		`for (int j = 0; j < COL; j++)`
		`{`
			`if (map[i][j] >= 0 && map[i][j] <= 8)`
			`{`
				`putimage(j * imgsize, i * imgsize, &img[map[i][j]]);`
			`}`
			`if (map[i][j] == -1)`
			`{`
				`putimage(j * imgsize, i * imgsize, &img[9]);`
			`}`
			`if (map[i][j] >= 19 && map[i][j] <= 28)`
			`{`
				`putimage(j * imgsize, i * imgsize,&img[10]);`
			`}`
			`if (map[i][j] >= 39)`
			`{`
				`putimage(j * imgsize, i * imgsize, &img[11]);`
			`}`
		`}`
	`}`
`}`

## 2.如何处理打开空白格时的连环反应

解决方案：递归（学递归最有用的一回

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



