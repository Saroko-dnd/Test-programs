#include <Windows.h>
#include "WindowProcedure.h"

LRESULT CALLBACK MainWindowProcedure(HWND hWnd, // дескриптор окошка
	UINT uMsg, // сообщение, посылаемое ОС
	WPARAM wParam, // параметры
	LPARAM lParam) // сообщений, для последующего обращения
{
	switch (uMsg)
	{
	case WM_DESTROY: // если окошко закрылось, то:
		PostQuitMessage(NULL); // отправляем WinMain() сообщение WM_QUIT
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return NULL;
}