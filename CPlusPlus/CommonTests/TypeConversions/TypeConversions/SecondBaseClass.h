#pragma once

#include <iostream>

using namespace std;

class SecondBase
{
public:
	string CurrentStringValue;

	SecondBase()
	{

	}

	SecondBase(string NewValue)
	{
		CurrentStringValue = NewValue;
	}

	virtual ~SecondBase()
	{

	}
};