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
using namespace std;
using namespace Gdiplus;
class My_Game
{
public:
	LRESULT GAME(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, Block block[10][10]);
};

