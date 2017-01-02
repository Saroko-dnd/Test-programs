// LambdaExpressions.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <algorithm> 
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int ArrayOfIntegers[] = {10,20,9,78,54,77,6,1,4,33};
	string CompareInfoMessage = "Number of comparisons: ";
	int ComparisonCounter = 0;
	vector<int> VectorWithIntegers(ArrayOfIntegers, ArrayOfIntegers + 10);

	std::sort(VectorWithIntegers.begin(), VectorWithIntegers.end(), [&ComparisonCounter](int LeftInt, int RightInt) {++ComparisonCounter;  return LeftInt > RightInt; });
	cout << "Descending sorting:\r\n";
	for (vector<int>::iterator PointerToInteger = VectorWithIntegers.begin(); PointerToInteger != VectorWithIntegers.end(); ++PointerToInteger)
	{
		cout << *PointerToInteger << " ";
	}
	cout << CompareInfoMessage << ComparisonCounter << "\r\n";
	ComparisonCounter = 0;

	std::sort(VectorWithIntegers.begin(), VectorWithIntegers.end(), [&ComparisonCounter](int LeftInt, int RightInt) {++ComparisonCounter; return LeftInt < RightInt; });
	cout << "Ascending sorting:\r\n";
	for (vector<int>::iterator PointerToInteger = VectorWithIntegers.begin(); PointerToInteger != VectorWithIntegers.end(); ++PointerToInteger)
	{
		cout << *PointerToInteger << " ";
	}
	cout << CompareInfoMessage << ComparisonCounter << "\r\n";

	system("pause");
    return 0;
}

