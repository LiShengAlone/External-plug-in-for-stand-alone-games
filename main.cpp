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
		printf("*-----------------------------����˹����  ��Ϸ���--------------------------------*\n");
		printf("*		�����	O		�޸Ľ�Ǯ	W		  *\n");
		printf("*		�޸�		H		�˳����	E		  *\n");
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
					hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Pid);//PROCESS_ALL_ACCESS ȡ��ȫ��Ȩ��
					if (hProcess == 0)
					{
						printf("\n����Ϸ����ʧ�ܣ�\n");
					}
					else
					{
						printf("����Ϸ���̳ɹ���\n");
					}
				}
				else
				{
					printf("\nδ�ҵ���Ϸ����\n");
				}
			}
			if (Command == 'W' || Command == 'w')
			{
				if (hProcess == 0)
				{
					printf("���ȴ���ң�\n");
				}
				else
				{
					DWORD Money;
					DWORD Add = 0x011750C8;
					printf("��������Ҫ����:");
					scanf("%d", &Money);
					DWORD res = WriteProcessMemory(hProcess, (LPVOID)Add, &Money, 4, 0);
					if (res == 0)
					{
						printf("\n�޸�ʧ��\n");
					}
					else
					{
						printf("\n�޸ĳɹ�\n");
					}
				}
			}
			if (Command == 'H' || Command == 'h')
			{
				if (hProcess == 0)
				{
					printf("���ȴ���ң�\n");
				}
				else
				{
					DWORD Speed;
					DWORD Add = 0x011750C8;
					printf("��������Ҫ���ٶ�:");
					scanf("%d", &Speed);
					DWORD res = WriteProcessMemory(hProcess, (LPVOID)Add, &Speed, 4, 0);
					if (res == 0)
					{
						printf("\n�޸�ʧ��\n");
					}
					else
					{
						printf("\n�޸ĳɹ�\n");
					}
				}
			}
		}
	}
	return 0;
}