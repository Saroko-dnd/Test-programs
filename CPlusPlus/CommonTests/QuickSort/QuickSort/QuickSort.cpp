// QuickSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "QuickSortFunction.h"

using namespace std;

int main()
{
	int ArraySize = 11;
	int TestIntArray[11] = { 1, 1, 10, 8, 9, 1, 1, 1, 5, 1, 1};

	cout << "Array before my QuickSort function" << endl;
	for (int index = 0; index < ArraySize; ++index)
	{
		cout << TestIntArray[index] << " ";
	}

	cout << "\r\n";
	QuickSort<int>(TestIntArray, 0, 10);

	cout << "\r\nArray after my QuickSort function" << endl;
	for (int index = 0; index < ArraySize; ++index)
	{
		cout << TestIntArray[index] << " ";
	}
	cout << "\r\n";
	system("Pause");
    return 0;
}

