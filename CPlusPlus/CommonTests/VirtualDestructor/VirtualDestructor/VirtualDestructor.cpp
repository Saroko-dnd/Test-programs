// VirtualDestructor.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "ClassesWithoutVirtualDestructor.h"
#include "ClassesUsingVirtualDestructor.h"

int main()
{
	//�������� ������������ ������ ��� ���������� � �������� ������ ������������ ����������� (�� ����������� ���������� ������������ ������)
	cout << "Base class HAS NO virtual destructor:\r\n\r\n";
	BaseClass *FirstTestObject = new DerivedClass();
	delete FirstTestObject;
	cout << "\r\n";
	//�������� ������������ ������ ��� ������� � �������� ������ ������������ ����������� (���������� ����������� ����� �������)
	cout << "Base class HAS virtual destructor:\r\n\r\n";
	BaseClassWithVirtualDestructor *SecondTestObject = new SecondDerivedClass();
	delete SecondTestObject;
	cout << "\r\n";
	system("Pause");
    return 0;
}

