// SmartPointer.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "PointerClass.h"
#include "TestClass.h"

using namespace std;

int main()
{
	SmartPointer<TestClass> TestPointer(new TestClass(5));

	cout << TestPointer->Number << endl;

	system("Pause");
    return 0;
}

