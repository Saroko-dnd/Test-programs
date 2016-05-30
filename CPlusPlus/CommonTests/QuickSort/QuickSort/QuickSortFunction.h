#pragma once

#include "QuickSortFunction.cpp"

template <typename ArrayType>
void QuickSort(ArrayType* Array, int LeftPosition, int RightPosition)
{
	int MiddleElementValue = Array[(RightPosition + LeftPosition) / 2];
	int LeftPosCopy = LeftPosition;
	int RightPosCopy = RightPosition;

	while (LeftPosCopy <= RightPosCopy)
	{
		while (Array[LeftPosCopy] < MiddleElementValue)
		{
			LeftPosCopy++;
		}
		while (Array[RightPosCopy] > MiddleElementValue)
		{
			RightPosCopy--;
		}
		if (LeftPosCopy <= RightPosCopy)
		{
			swap(Array[LeftPosCopy], Array[RightPosCopy]);
			LeftPosCopy++;
			RightPosCopy--;
		}
	}

	for (int index = 0; index < 11; ++index)
	{
		cout << Array[index] << " ";
	}
	cout << "\r\n";

	if (LeftPosition < RightPosCopy)
	{
		QuickSort(Array, LeftPosition, RightPosCopy);
	}
	if (RightPosition > LeftPosCopy)
	{
		QuickSort(Array, LeftPosCopy, RightPosition);
	}

}