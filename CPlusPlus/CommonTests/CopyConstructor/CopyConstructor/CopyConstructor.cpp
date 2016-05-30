// CopyConstructor.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ClassWithCopyConstructor.h"
#include <iostream>

using namespace std;

int main()
{
	ClassWithCopyCunstructor* TestObject = new ClassWithCopyCunstructor();

	cout << "Before copy constructor:\r\n";
	for (int index = 0; index < ClassWithCopyCunstructor::SizeOfArray; ++index)
	{
		cout << TestObject->IntPointer[index] << endl;
	}

	cout << "\r\nAfter copy constructor:\r\n";
	TestFunction(*TestObject);

	system("Pause");

    return 0;
}

