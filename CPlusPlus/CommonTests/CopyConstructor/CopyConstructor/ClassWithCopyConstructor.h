#pragma once

class ClassWithCopyCunstructor
{
	public:
		static const int SizeOfArray = 5;

		int* IntPointer;

		ClassWithCopyCunstructor();

		~ClassWithCopyCunstructor()
		{
			delete IntPointer;
		}

		//Конструктор копирования
		ClassWithCopyCunstructor(const ClassWithCopyCunstructor& ObjectForCopy);
};

void TestFunction(ClassWithCopyCunstructor CurrentObject);