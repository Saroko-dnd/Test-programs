#pragma once

#include <Windows.h>

bool WC_RegisterWindowClass(TCHAR NewClassName[], HINSTANCE CurrentApplicationInstanceHandler);

HWND WC_CreateWindow(TCHAR ClassName[], HINSTANCE CurrentApplicationInstanceHandler);

WPARAM WC_ActivateWindow(HWND CurrentWindowHandler, int ShowCommand);

