#include <windows.h> // ������������ ����, ���������� ������� API

// �������� ������� - ������ int main() � ���������� ����������:
int WINAPI WinMain(HINSTANCE hInstance, // ���������� ���������� ����������
	HINSTANCE hPrevInstance, // � Win32 �� ������������
	LPSTR lpCmdLine, // ����� ��� ������� ���� � ������ ��������� ������
	int nCmdShow) // ����� ����������� ����
{
	// ������� ������ ���� � ������� "��" �� ����� (� ���������� �����)
	int FirstQuestionResult = MessageBox(NULL, TEXT("�� ����?"), TEXT("������"), MB_ICONQUESTION|MB_YESNO);
	if (FirstQuestionResult == IDYES)
	{
		MessageBox(NULL, TEXT("�� ���� ����� ���! ������ �� ����������!"), TEXT("�� ������"), MB_ICONERROR|MB_OK);
	}
	else
	{
		MessageBox(NULL, TEXT("��������� �� ���������"), TEXT("�� ������ ������"), MB_ICONINFORMATION|MB_OK);
	}
	return NULL; // ���������� �������� �������
}