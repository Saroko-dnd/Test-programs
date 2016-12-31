#pragma once

#include <iostream>
#include "SecondBaseClass.h"

using namespace std;

class SecondDerived : public SecondBase
{
public:
	int TestInt;

	SecondDerived()
	{
		TestInt = 8;
	}

	SecondDerived(string NewValue) : SecondBase(NewValue)
	{
		TestInt = 8;
	}

	~SecondDerived()
	{

	}
};