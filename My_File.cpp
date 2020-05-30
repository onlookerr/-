#include "stdafx.h"
#include "My_File.h"
#include "������1.0.h"
#include <stdio.h>
void TcharToChar(const TCHAR * tchar, char * _char);//ת���ַ�����
void CharToTchar(const char * _char, TCHAR * tchar);
#define B_SAVE		3000
LRESULT My_File::File(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND staticwin = NULL;
	static HWND editwin = NULL;
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case B_SAVE:
		{
			static TCHAR szUsername[100];
			GetWindowText(editwin, szUsername, 100);
			if (Is_Relax)
			{
				if (MessageBox(hWnd, szUsername, TEXT("��ȷ��"), MB_YESNO) == IDYES)
				{
					HANDLE hFile;
					hFile = CreateFile(L"relax.txt",
						GENERIC_WRITE,
						FILE_SHARE_WRITE,
						NULL,
						OPEN_ALWAYS,
						FILE_ATTRIBUTE_NORMAL,
						NULL);//ʹ��CreatFile���API�������ļ�   
					SetFilePointer(hFile, 0, NULL, FILE_END);
					DWORD Written;
					char temp[100];
					TcharToChar(szUsername, temp);
					WriteFile(hFile, temp, strlen(temp), &Written, NULL);
					WriteFile(hFile, "	", strlen("	"), &Written, NULL);
					char num_s[10];
					sprintf_s(num_s, "%d", gscore);
					WriteFile(hFile, "�÷�:", strlen("�÷�:"), &Written, NULL);
					WriteFile(hFile, num_s, strlen(num_s), &Written, NULL);
					WriteFile(hFile, "	", strlen("	"), &Written, NULL);
					char num_t[10];
					sprintf_s(num_t, "%d", GTIMER / 20);
					WriteFile(hFile, "��ʱ:", strlen("��ʱ:"), &Written, NULL);
					WriteFile(hFile, num_t, strlen(num_t), &Written, NULL);
					WriteFile(hFile, " ��", strlen(" ��"), &Written, NULL);
					WriteFile(hFile, "\r\n", strlen("\r\n"), &Written, NULL);
					CloseHandle(hFile);//�رվ��   


					gscore = 0;
					GTIMER = 0;


					HANDLE RhFile;//����һ�������   
					RhFile = CreateFile(L"relax.txt",
						GENERIC_READ,
						FILE_SHARE_READ,
						NULL,
						OPEN_EXISTING,
						FILE_ATTRIBUTE_NORMAL,
						NULL);//ʹ��CreatFile���API�������ļ�   
					DWORD dwDataLen;
					char FileContent[1000];
					ReadFile(RhFile, FileContent, 1000, &dwDataLen, NULL);//��ȡ����   
					FileContent[dwDataLen] = 0;//������δβ���㡣   
					CloseHandle(RhFile);//�رվ��   
					TCHAR Tfilecontent[100];
					CharToTchar(FileContent, Tfilecontent);
					MessageBox(hWnd, Tfilecontent, TEXT("�ɼ�"), MB_OK);//������  
					DestroyWindow(hWnd);
				}
			}

			if (Is_Infinite)
			{
				if (MessageBox(hWnd, szUsername, TEXT("��ȷ��"), MB_YESNO) == IDYES)
				{
					HANDLE hFile;
					hFile = CreateFile(L"infinite.txt",
						GENERIC_WRITE,
						FILE_SHARE_WRITE,
						NULL,
						OPEN_ALWAYS,
						FILE_ATTRIBUTE_NORMAL,
						NULL);//ʹ��CreatFile���API�������ļ�   
					SetFilePointer(hFile, 0, NULL, FILE_END);
					DWORD Written;
					char temp[100];
					TcharToChar(szUsername, temp);
					WriteFile(hFile, temp, strlen(temp), &Written, NULL);
					WriteFile(hFile, "	", strlen("	"), &Written, NULL);
					char num[10];
					sprintf_s(num, "%d", Round);
					WriteFile(hFile, "�ɼ�:", strlen("�ɼ�:"), &Written, NULL);
					WriteFile(hFile, num, strlen(num), &Written, NULL);
					WriteFile(hFile, "��", strlen("��"), &Written, NULL);
					WriteFile(hFile, "\r\n", strlen("\r\n"), &Written, NULL);
					CloseHandle(hFile);//�رվ��   

					gscore = 0;
					GTIMER = 0;


					HANDLE RhFile;//����һ�������   
					RhFile = CreateFile(L"infinite.txt",
						GENERIC_READ,
						FILE_SHARE_READ,
						NULL,
						OPEN_EXISTING,
						FILE_ATTRIBUTE_NORMAL,
						NULL);//ʹ��CreatFile���API�������ļ�   
					DWORD dwDataLen;
					char FileContent[1000];
					ReadFile(RhFile, FileContent, 1000, &dwDataLen, NULL);//��ȡ����   
					FileContent[dwDataLen] = 0;//������δβ���㡣   
					CloseHandle(RhFile);//�رվ��   
					TCHAR Tfilecontent[100];
					CharToTchar(FileContent, Tfilecontent);
					MessageBox(hWnd, Tfilecontent, TEXT("�ɼ�"), MB_OK);//������  
					DestroyWindow(hWnd);
				}
			}

			break;
		}
		break;
		}

		break;
	}
	case WM_CREATE:
	{
		staticwin = CreateWindow(TEXT("static"), TEXT("������֣�"),
			WS_CHILD | WS_VISIBLE,
			10, 25, 200, 24,
			hWnd, NULL, NULL, NULL);
		editwin = CreateWindow(TEXT("edit"), TEXT(""),
			WS_CHILD | WS_VISIBLE | WS_BORDER /*�߿�*/ | ES_AUTOHSCROLL /*ˮƽ����*/,
			80, 25, 150, 26,
			hWnd, NULL, NULL, NULL);
		CreateWindow(L"Button", L"ȷ��", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
			80, 100, 100, 50, hWnd, (HMENU)B_SAVE, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);
		break;
	}
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

void TcharToChar(const TCHAR * tchar, char * _char)
{
	int iLength;
	//��ȡ�ֽڳ���   
	iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
	//��tcharֵ����_char    
	WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}

void CharToTchar(const char * _char, TCHAR * tchar)
{
	int iLength;

	iLength = MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, NULL, 0);
	MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, tchar, iLength);
}