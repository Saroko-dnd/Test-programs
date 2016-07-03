#include "TestClassWithTwoInt.h"

//Impossible to use for initialization of array
TestClassWithTwoInt::TestClassWithTwoInt(int ValueForFirstInt, int ValueOfSecondInt)
{
	FirstInt = ValueForFirstInt;
	SecondInt = ValueOfSecondInt;
}

//Possible to use for initialization of array
TestClassWithTwoInt::TestClassWithTwoInt()
{
	FirstInt = 5;
	SecondInt = 8;
}