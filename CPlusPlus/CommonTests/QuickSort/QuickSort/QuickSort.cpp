// QuickSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "QuickSortFunction.h"

using namespace std;

int main()
{
	int ArraySize = 9;
	int TestIntArray[9] = { 1, 2, 3, 3, 4, 2, 3, 4, 6};

	cout << "Array before my QuickSort function" << endl;
	for (int index = 0; index < ArraySize; ++index)
	{
		cout << TestIntArray[index] << " ";
	}

	cout << "\r\n";
	QuickSort<int>(TestIntArray, 0, 8);

	cout << "\r\nArray after my QuickSort function" << endl;
	for (int index = 0; index < ArraySize; ++index)
	{
		cout << TestIntArray[index] << " ";
	}
	cout << "\r\n";
	system("Pause");
    return 0;
}

