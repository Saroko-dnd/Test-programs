// PureVirtualFunctionCall Exception.cpp: ���������� ����� ����� ��� ����������� ����������.
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

