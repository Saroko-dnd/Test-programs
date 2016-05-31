// InvertingString.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "InvertStringFunction.h"
#include <string>
#include <iostream>

using namespace std;


int main()
{
	string TestString = "I am your doom!!!";

	cout << "Original string:" << endl;
	cout << TestString << endl;

	TestString = InvertString(TestString);

	cout << "Inverted string:" << endl;
	cout << TestString << endl;

	system("Pause");
    return 0;
}

