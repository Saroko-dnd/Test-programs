#include <Windows.h>
#include "WindowProcedure.h"
#include "MyResources.h"

LRESULT CALLBACK MainWindowProcedure(HWND hWnd, // дескриптор окошка
	UINT uMsg, // сообщение, посылаемое ќ—
	WPARAM wParam, // параметры
	LPARAM lParam) // сообщений, дл€ последующего обращени€
{
	switch (uMsg)
	{
		//¬ момент создани€ окна снабжаем его меню новыми иконками
		case WM_CREATE:
		{
			SetNewIconsForMenu(hWnd, MENU_FILE_NEW, FILE_NEW_ICON);
			SetNewIconsForMenu(hWnd, MENU_FILE_OPEN, FILE_OPEN_ICON);
			SetNewIconsForMenu(hWnd, MENU_FILE_ENCRYPT, FILE_ENCRYPT_ICON);
			SetNewIconsForMenu(hWnd, MENU_FILE_DECRYPT, FILE_DECRYPT_ICON);
			SetNewIconsForMenu(hWnd, MENU_FILE_EXIT, FILE_EXIT_ICON);
			break;
		}
		case WM_COMMAND:
			//ќбработка сообщений от меню окна
			ProcessingMenuCommands(hWnd, wParam);
			break;
		case WM_DESTROY: // если окошко закрылось, то:
			PostQuitMessage(NULL); // отправл€ем WinMain() сообщение WM_QUIT
			break;
		default:
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return NULL;
}

//Ёта фуннкци€ обрабатывает взаимодействие пользовател€ с меню окна
void ProcessingMenuCommands(HWND CurrentWindowHandler, WPARAM CurrentMenuID)
{
	switch (CurrentMenuID)
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
		case MENU_TEXT_BOLD:
			ChangeMenuState(CurrentWindowHandler, MENU_TEXT_BOLD);
			break;
		case MENU_TEXT_ITALIC:
			ChangeMenuState(CurrentWindowHandler, MENU_TEXT_ITALIC);
			break;
		case MENU_TEXT_UNDERLINE:
			ChangeMenuState(CurrentWindowHandler, MENU_TEXT_UNDERLINE);
			break;
		case MENU_TIPS_ENABLE:
			ChangeAvailabilityOfTipsMenuItems(CurrentWindowHandler);
			break;
		case MENU_TIPS_DISABLE:
			ChangeAvailabilityOfTipsMenuItems(CurrentWindowHandler);
			break;
		case MENU_FILE_EXIT:
			//ѕрерываем цикл обработки сообщений (завершаем программу)
			PostQuitMessage(0);
			break;
	}
}

//”правл€ет доступностью пунктов меню подсказок
void ChangeAvailabilityOfTipsMenuItems(HWND CurrentWindowHandler)
{
	HMENU CurrentMenu = GetMenu(CurrentWindowHandler);
	UINT CurrentMenuState = GetMenuState(CurrentMenu, MENU_TIPS_ENABLE, MF_BYCOMMAND);
	if (CurrentMenuState == MF_GRAYED)
	{
		EnableMenuItem(CurrentMenu, MENU_TIPS_ENABLE, MF_BYCOMMAND | MF_ENABLED);
		EnableMenuItem(CurrentMenu, MENU_TIPS_DISABLE, MF_BYCOMMAND | MF_GRAYED);
	}
	else
	{
		EnableMenuItem(CurrentMenu, MENU_TIPS_ENABLE, MF_BYCOMMAND | MF_GRAYED);
		EnableMenuItem(CurrentMenu, MENU_TIPS_DISABLE, MF_BYCOMMAND | MF_ENABLED);
	}
}

//»змен€ет состо€ние выбранного MENUITEM на противоположное (убирает или добавл€ет иконку с галочкой)
void ChangeMenuState(HWND CurrentWindowHandler, UINT MenuID)
{
	HMENU CurrentMenu = GetMenu(CurrentWindowHandler);
	UINT CurrentMenuState = GetMenuState(CurrentMenu, MenuID, MF_BYCOMMAND);
	if (CurrentMenuState == MF_CHECKED)
	{
		CheckMenuItem(CurrentMenu, MenuID, MF_UNCHECKED);
	}
	else
	{
		CheckMenuItem(CurrentMenu, MenuID, MF_CHECKED);
	}
}

//”станавливает новую иконку дл€ выбранного MENUITEM в меню указанного окна
void SetNewIconsForMenu(HWND CurrentWindowHandler, UINT MenuID, UINT IconID)
{
	HINSTANCE ApplicationHandler = GetModuleHandle(NULL);
	HBITMAP NewIcon = LoadBitmap(ApplicationHandler, MAKEINTRESOURCE(IconID));
	HMENU CurrentMenu = GetMenu(CurrentWindowHandler);
	SetMenuItemBitmaps(CurrentMenu, MenuID, MF_BYCOMMAND, NewIcon, NewIcon);
}