// Templates.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Calculator.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	Calculator<char, int> FirstTestCalculator('h', 7);
	FirstTestCalculator.Sum();
	cout << "\r\n";
	Calculator<int, int> SecondTestCalculator(5, 7);
	SecondTestCalculator.Sum();
	cout << "\r\n";
	//Calculator<string, int> SecondTestCalculator("text", 7);  Compile error from static_assert function inside class Calculator (because string is not an arithmetic type)
	system("pause");
    return 0;
}

