#include <Windows.h>
#include "WindowProcedure.h"

int WINAPI WinMain(HINSTANCE hInst,
	HINSTANCE hPreviousInst,
	LPSTR lpCommandLine,
	int nCommandShow
	)
{
	TCHAR WindowClassName[] = TEXT("Имя моего класса");
	// создаём дескриптор окна
	HWND WindowHandler;
	
	// описываем класс окна
	WNDCLASSEX WindowStruct;
	WindowStruct.cbSize = sizeof(WNDCLASSEX);//Стандартное значение
	WindowStruct.style = CS_HREDRAW | CS_VREDRAW;
	WindowStruct.lpfnWndProc = MainWindowProcedure;//Указываем процедуру для данного окна
	WindowStruct.cbClsExtra = NULL;//Стандартное значение
	WindowStruct.cbWndExtra = NULL;//Почти всегда NULL, за исключением: If an application uses WNDCLASSEX to register a dialog box created by using the CLASS directive in the resource file, 
	//it must set this member to DLGWINDOWEXTRA
	WindowStruct.hInstance = hInst;//Указываем, что оконная процедура находится в этом процессе
	WindowStruct.hIcon = LoadIcon(NULL, IDI_INFORMATION);//A handle to the class icon. If set to NULL, then it will be default icon.
	WindowStruct.hIconSm = LoadIcon(NULL, IDI_INFORMATION); //A handle to a small icon that is associated with the window class. If set to NULL then window will have default small icon.
	WindowStruct.hCursor = LoadCursor(NULL, IDC_CROSS);//A handle to the class cursor. If set to NULL, then it will be default cursor.
	WindowStruct.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH); //A handle to the class background brush. If set to NULL, then background has a color based on current client area settings (default). 
	WindowStruct.lpszMenuName = NULL;//Pointer to a null-terminated character string that specifies the resource name of the class menu, as the name appears in the resource file.
	//NULL if we dont have any menu
	WindowStruct.lpszClassName = WindowClassName;//Можно также = TEXT("Имя моего класса");

	//Регистрируем класс окна для дальнейшего использования при создании окна(окон)
	if (!RegisterClassEx(&WindowStruct)) 
	{
		// Если не удалось зарегистрировать класс:
		MessageBox(NULL, TEXT("Не получилось зарегистрировать класс!"), TEXT("Ошибка"), MB_OK|MB_ICONERROR);
		return NULL; // возвращаем, следовательно, выходим из WinMain
	}
	// создаём окошко, показываем его на экране
	// возвращаем значение при неудаче или при выходе
}