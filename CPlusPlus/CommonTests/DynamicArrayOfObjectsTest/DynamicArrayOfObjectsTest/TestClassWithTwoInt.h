#pragma once

class TestClassWithTwoInt
{
	public:
		int FirstInt;
		int SecondInt;

		//Impossible to use for initialization of array
		TestClassWithTwoInt(int ValueForFirstInt, int ValueOfSecondInt);
		//Possible to use for initialization of array
		TestClassWithTwoInt();
};