#pragma once

#include <Windows.h>

LRESULT CALLBACK MainWindowProcedure(HWND, UINT, WPARAM, LPARAM);

void ChangeMenuState(HWND CurrentWindowHandler, UINT MenuID);

void SetNewIconsForMenu(HWND CurrentWindowHandler, UINT MenuID, UINT IconID);



