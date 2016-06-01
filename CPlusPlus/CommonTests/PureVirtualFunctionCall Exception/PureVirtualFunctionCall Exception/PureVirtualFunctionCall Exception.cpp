// PureVirtualFunctionCall Exception.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "AbstractAndDerivedClasses.h"
#include <iostream>

using namespace std;

int main()
{
	DerivedClass TestObject;

	TestObject.PureVirtualFunction();

	system("Pause");
    return 0;
}

