#include <Windows.h>
#include "WindowProcedure.h"

int WINAPI WinMain(HINSTANCE hInst,
	HINSTANCE hPreviousInst,
	LPSTR lpCommandLine,
	int nCommandShow
	)
{
	// создаём дескриптор окна
	HWND WindowHandler;
	// описываем класс окна
	WNDCLASSEX WindowStruct;
	WindowStruct.cbSize = sizeof(WNDCLASSEX);//Стандартное значение
	WindowStruct.style = CS_HREDRAW | CS_VREDRAW;
	WindowStruct.lpfnWndProc = MainWindowProcedure;
	WindowStruct.cbClsExtra = NULL;//Стандартное значение
	WindowStruct.cbWndExtra = NULL;//Почти всегда NULL, за исключением: If an application uses WNDCLASSEX to register a dialog box created by using the CLASS directive in the resource file, 
	//it must set this member to DLGWINDOWEXTRA
	// создаём окошко, показываем его на экране
	// возвращаем значение при неудаче или при выходе
}