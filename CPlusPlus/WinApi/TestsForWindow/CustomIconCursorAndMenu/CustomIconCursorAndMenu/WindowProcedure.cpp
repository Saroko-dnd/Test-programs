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
			//Обработка сообщений от меню окна
			switch (wParam)
			{
				case MENU_FILE_NEW:
					MessageBox(NULL, MYRES_MESSAGEBOX_FILE_NEW, MYRES_MESSAGEBOX_HEADER, MB_OK | MB_ICONASTERISK);
					break;
				case MENU_FILE_OPEN:
					MessageBox(NULL, MYRES_MESSAGEBOX_FILE_OPEN, MYRES_MESSAGEBOX_HEADER, MB_OK | MB_ICONASTERISK);
					break;
				case MENU_FILE_ENCRYPT:
					MessageBox(NULL, MYRES_MESSAGEBOX_FILE_ENCRYPT, MYRES_MESSAGEBOX_HEADER, MB_OK | MB_ICONASTERISK);
					break;
				case MENU_FILE_DECRYPT:
					MessageBox(NULL, MYRES_MESSAGEBOX_FILE_DECRYPT, MYRES_MESSAGEBOX_HEADER, MB_OK | MB_ICONASTERISK);
					break;
				case MENU_FILE_EXIT:
					//Прерываем цикл обработки сообщений (завершаем программу)
					PostQuitMessage(0); 
					break;
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