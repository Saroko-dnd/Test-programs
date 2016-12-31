#pragma once

#include <iostream>

using namespace std;

class Base
{
	public:
		int CurrentValue;

		Base()
		{

		}

		Base(int NewValue)
		{
			CurrentValue = NewValue;
		}

		virtual ~Base()
		{

		}
};