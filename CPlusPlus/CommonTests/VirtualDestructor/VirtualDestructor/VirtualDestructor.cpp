// VirtualDestructor.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ClassesWithoutVirtualDestructor.h"
#include "ClassesUsingVirtualDestructor.h"

int main()
{
	//Создание производного класса при отсутствии у базового класса виртуального деструктора (не выполняется деструктор производного класса)
	cout << "Base class HAS NO virtual destructor:\r\n\r\n";
	BaseClass *FirstTestObject = new DerivedClass();
	delete FirstTestObject;
	cout << "\r\n";
	//Создание производного класса при наличии у базового класса виртуального деструктора (вызываются деструкторы обоих классов)
	cout << "Base class HAS virtual destructor:\r\n\r\n";
	BaseClassWithVirtualDestructor *SecondTestObject = new SecondDerivedClass();
	delete SecondTestObject;
	cout << "\r\n";
	system("Pause");
    return 0;
}

