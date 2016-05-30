
#include "ClassWithCopyConstructor.h"
#include <iostream>

using namespace std;

ClassWithCopyCunstructor::ClassWithCopyCunstructor()
{
	IntPointer = new int[5]();
	IntPointer[0] = 1;
	IntPointer[1] = 2;
	IntPointer[2] = 3;
	IntPointer[3] = 4;
	IntPointer[4] = 5;
}

//Конструктор копирования, который заполняет весь массив пятерками
ClassWithCopyCunstructor::ClassWithCopyCunstructor(const ClassWithCopyCunstructor& ObjectForCopy)
{
	IntPointer = new int[5]();
	for (int index = 0; index < ClassWithCopyCunstructor::SizeOfArray; ++index)
	{
		IntPointer[index] = 5;
	}
}

void TestFunction(ClassWithCopyCunstructor CurrentObject)
{
	for (int index = 0; index < ClassWithCopyCunstructor::SizeOfArray; ++index)
	{
		cout << CurrentObject.IntPointer[index] << endl;
	}
}
