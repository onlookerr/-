#pragma once
#include "stdafx.h"
#include "windowsx.h"
#include "������1.0.h"
#include <comdef.h>
#include <GdiPlus.h>//����gdi+ͷ�ļ�
#pragma comment(lib, "Gdiplus.lib")//����GDI+�Ŀ�
#include "time.h"
#include "My_Struct.h"
#include "My_Image.h"
#include "My_Rule.h"
#include "My_Menu.h"
class My_File
{
public:
	LRESULT File(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};