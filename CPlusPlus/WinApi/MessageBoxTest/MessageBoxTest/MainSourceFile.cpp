#include <windows.h> // заголовочный файл, содержащий функции API

// Основная функция - аналог int main() в консольном приложении:
int WINAPI WinMain(HINSTANCE hInstance, // дескриптор экземпляра приложения
	HINSTANCE hPrevInstance, // в Win32 не используется
	LPSTR lpCmdLine, // нужен для запуска окна в режиме командной строки
	int nCmdShow) // режим отображения окна
{
	// Функция вывода окна с кнопкой "ОК" на экран (о параметрах позже)
	int FirstQuestionResult = MessageBox(NULL, TEXT("Ты эльф?"), TEXT("Вопрос"), MB_ICONQUESTION|MB_YESNO);
	if (FirstQuestionResult == IDYES)
	{
		MessageBox(NULL, TEXT("Не смей лгать мне! Эльфов не существует!"), TEXT("Ты солгал"), MB_ICONERROR|MB_OK);
	}
	else
	{
		MessageBox(NULL, TEXT("Благодарю за честность"), TEXT("Ты сказал правду"), MB_ICONINFORMATION|MB_OK);
	}
	return NULL; // возвращаем значение функции
}