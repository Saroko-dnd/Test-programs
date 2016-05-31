
#include "InvertStringFunction.h"

using namespace std;

string InvertString(string CurrentString)
{
	int SizeOfCurrentString = CurrentString.size();

	for (int index = 0; index < SizeOfCurrentString / 2; ++index)
	{
		swap(CurrentString[index], CurrentString[SizeOfCurrentString - index - 1]);
	}

	return CurrentString;
}