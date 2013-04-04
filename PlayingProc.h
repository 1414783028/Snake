#pragma once

//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <windows.h>

#include "Init_Playing_Map.h"
#include "MacroDefine.h"
#include "cu_map.h"
#include "resource.h"

//////////////////////////////////////////////////////////////////////////

typedef struct GameStatus
{
	TCHAR	szGameTitle[256];		//����������
	int		level;					//��ǰ��Ϸ����
	POINT	head;					//��ͷ����������
	POINT	food;					//ʳ����������
	int		len;					//������
	int		score;					//��Ϸ�÷�
}GM_STATUS;

//////////////////////////////////////////////////////////////////////////

LRESULT PlayingProc( HWND, UINT, WPARAM, LPARAM );

BOOL PointImpaceTest( HWND, POINT );			//�����ϰ������ײ���
