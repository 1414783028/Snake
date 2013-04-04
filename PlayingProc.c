#include "PlayingProc.h"

//////////////////////////////////////////////////////////////////////////

LRESULT PlayingProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	HDC hdc;
	PAINTSTRUCT ps;

	POINT ptWall[2] = {0};

	switch( message )
	{
	case WM_TIMER:
		switch( wParam )
		{
		case TMR_PLAYING_READY:
			SetTimer( hwnd, TMR_PLAYING_READY, 1000*60, NULL );			//������ʱ��Ϊ60��
			PlaySound( MAKEINTRESOURCE( IDR_READY ), (HINSTANCE)GetWindowLong( hwnd, GWL_HINSTANCE ), SND_RESOURCE | SND_ASYNC );
			KillTimer( hwnd, TMR_PLAYING_READY );
			SetTimer( hwnd, TMR_PLAYING_GO, 2000, NULL );			//������Ϸ������ʱ��
			break;

		case TMR_PLAYING_GO:
			KillTimer( hwnd, TMR_PLAYING_GO );
			PlaySound( MAKEINTRESOURCE( IDR_GO ), (HINSTANCE)GetWindowLong( hwnd, GWL_HINSTANCE ), SND_RESOURCE | SND_ASYNC );
			//��Ϸ��ʼ
			break;
		}
		return 0;

	case WM_PAINT:
		hdc = BeginPaint( hwnd, &ps );
		InitPlayingMap( hwnd, hdc, (HINSTANCE)GetWindowLong( hwnd, GWL_HINSTANCE ) );
		InitRandWallPos( hwnd, ptWall );
		DrawRandWall( hwnd, hdc, ptWall );
		EndPaint( hwnd, &ps );
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc( hwnd, message, wParam, lParam );
}