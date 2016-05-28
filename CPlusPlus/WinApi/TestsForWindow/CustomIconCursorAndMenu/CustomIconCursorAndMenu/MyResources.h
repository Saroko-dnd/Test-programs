#pragma once

#include <Windows.h>

//Устанавливаем идентификатор для  нашего курсора
#define CURSOR_GREEN 1000
//Устанавливаем идентификатор для нашей иконки
#define FOX_ICON 1001
//Устанавливаем идентификаторы для меню 
//****************************************
#define NEW_MENU 1002 //имя ресурса
//идентификаторы подменю
#define MENU_FILE_NEW	1003
#define MENU_FILE_OPEN	1004
#define MENU_FILE_EXIT	1005
#define MENU_FILE_ENCRYPT	1006
#define MENU_FILE_DECRYPT	1007
#define MENU_TEXT_BOLD	1008
#define MENU_TEXT_ITALIC	1009
#define MENU_TEXT_UNDERLINE	1010
#define MENU_TIPS_ENABLE	1016
#define MENU_TIPS_DISABLE	1017

//идентификаторы иконок для меню
#define FILE_NEW_ICON	1011
#define FILE_OPEN_ICON	1012
#define FILE_ENCRYPT_ICON	1013
#define FILE_DECRYPT_ICON	1014
#define FILE_EXIT_ICON	1015

//Тексты для MessageBox
#define MYRES_MESSAGEBOX_HEADER TEXT("Уведомление")
#define MYRES_MESSAGEBOX_FILE_NEW TEXT("Вы попытались создать новый файл!")
#define MYRES_MESSAGEBOX_FILE_OPEN TEXT("Вы попытались открыть меню для поиска и загрузки уже созданных файлов!")
#define MYRES_MESSAGEBOX_FILE_ENCRYPT TEXT("Вы попытались зашифровать файл!")
#define MYRES_MESSAGEBOX_FILE_DECRYPT TEXT("Вы попытались расшифровать файл!")
//****************************************
