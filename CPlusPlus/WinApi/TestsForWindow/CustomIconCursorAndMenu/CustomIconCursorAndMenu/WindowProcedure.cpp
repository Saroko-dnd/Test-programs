#include <Windows.h>
#include "WindowProcedure.h"
#include "MyResources.h"

LRESULT CALLBACK MainWindowProcedure(HWND hWnd, // дескриптор окошка
	UINT uMsg, // сообщение, посылаемое ОС
	WPARAM wParam, // параметры
	LPARAM lParam) // сообщений, для последующего обращения
{
	switch (uMsg)
	{
	case WM_COMMAND:
		if (wParam == MENU_FILE_NEW)
		{
			MessageBox(NULL, TEXT("Вы попытались создать новый файл!"), MYRES_MESSAGEBOX_HEADER, MB_OK | MB_ICONASTERISK);
		}
		else if (wParam == MENU_FILE_OPEN)
		{
			MessageBox(NULL, TEXT("Вы попытались открыть меню для поиска и загрузки уже созданных файлов!"), MYRES_MESSAGEBOX_HEADER, MB_OK | MB_ICONASTERISK);
		}
		break;
	case WM_DESTROY: // если окошко закрылось, то:
		PostQuitMessage(NULL); // отправляем WinMain() сообщение WM_QUIT
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return NULL;
}