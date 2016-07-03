// DynamicArrayOfObjectsTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "TestClassWithTwoInt.h"
#include <iostream>

using namespace std;

int main()
{
	int SizeOfArray = 5;

	TestClassWithTwoInt *ArrayOfObjectsWithTwoIntNumbers = new TestClassWithTwoInt[SizeOfArray]();

	for (int index = 0; index < SizeOfArray; ++index)
	{
		cout << index + 1 << " object" << endl;
		cout << "FirstInt " << ArrayOfObjectsWithTwoIntNumbers[index].FirstInt << endl;
		cout << "SecondInt " << ArrayOfObjectsWithTwoIntNumbers[index].SecondInt << "\n\n";
	}

	system("Pause");

	delete[] ArrayOfObjectsWithTwoIntNumbers;

    return 0;
}

