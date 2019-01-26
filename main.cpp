#include<stdio.h>
#include<windows.h>
#include<conio.h>
int main()
{
	char Command;
	HWND hWnd;
	DWORD Pid;
	HANDLE hProcess = 0;
	while (1)
	{
		printf("*-----------------------------俄罗斯方块  游戏外挂--------------------------------*\n");
		printf("*		打开外挂	O		修改金钱	W		  *\n");
		printf("*		修改		H		退出外挂	E		  *\n");
		printf("***********************************************************************************\n");
		printf("\n");
		Command = getch();
		if (Command == 'E' || Command == 'e')
		{
			break;
		}
		else
		{
			if (Command == 'O' || Command == 'o')
			{
				hWnd = FindWindow(NULL, L"GameSnake");
				if (hWnd != 0)
				{
					GetWindowThreadProcessId(hWnd, &Pid);
					hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Pid);//PROCESS_ALL_ACCESS 取得全部权限
					if (hProcess == 0)
					{
						printf("\n打开游戏进程失败！\n");
					}
					else
					{
						printf("打开游戏进程成功！\n");
					}
				}
				else
				{
					printf("\n未找到游戏窗口\n");
				}
			}
			if (Command == 'W' || Command == 'w')
			{
				if (hProcess == 0)
				{
					printf("请先打开外挂！\n");
				}
				else
				{
					DWORD Money;
					DWORD Add = 0x011750C8;
					printf("输入您想要的数:");
					scanf("%d", &Money);
					DWORD res = WriteProcessMemory(hProcess, (LPVOID)Add, &Money, 4, 0);
					if (res == 0)
					{
						printf("\n修改失败\n");
					}
					else
					{
						printf("\n修改成功\n");
					}
				}
			}
			if (Command == 'H' || Command == 'h')
			{
				if (hProcess == 0)
				{
					printf("请先打开外挂！\n");
				}
				else
				{
					DWORD Speed;
					DWORD Add = 0x011750C8;
					printf("输入您想要的速度:");
					scanf("%d", &Speed);
					DWORD res = WriteProcessMemory(hProcess, (LPVOID)Add, &Speed, 4, 0);
					if (res == 0)
					{
						printf("\n修改失败\n");
					}
					else
					{
						printf("\n修改成功\n");
					}
				}
			}
		}
	}
	return 0;
}