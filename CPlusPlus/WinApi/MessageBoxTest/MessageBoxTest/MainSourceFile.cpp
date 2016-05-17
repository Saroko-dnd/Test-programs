#include <windows.h> // заголовочный файл, содержащий функции API

// Основная функция - аналог int main() в консольном приложении:
int WINAPI WinMain(HINSTANCE hInstance, // дескриптор экземпляра приложения
	HINSTANCE hPrevInstance, // в Win32 не используется
	LPSTR lpCmdLine, // нужен для запуска окна в режиме командной строки
	int nCmdShow) // режим отображения окна
{
	// Функция вывода окна с кнопкой "ОК" на экран (о параметрах позже)
	int FirstQuestionResult = MessageBox(NULL, L"Ты эльф?", L"Вопрос", MB_ICONQUESTION|MB_YESNO);
	if (FirstQuestionResult == IDYES)
	{
		MessageBox(NULL, L"Не смей лгать мне! Эльфов не существует!", L"Ты солгал", MB_ICONERROR|MB_OK);
	}
	else
	{
		MessageBox(NULL, L"Благодарю за честность", L"Ты сказал правду", MB_ICONINFORMATION|MB_OK);
	}
	return NULL; // возвращаем значение функции
}