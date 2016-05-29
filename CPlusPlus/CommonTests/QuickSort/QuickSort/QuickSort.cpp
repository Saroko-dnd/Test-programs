// QuickSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "QuickSortFunction.h"

using namespace std;

int main()
{
	int TestIntArray[5] = { 16, 2, 77, 40, 12071 };
	QuickSort<int>(TestIntArray, 0, 4);
	system("Pause");
    return 0;
}

