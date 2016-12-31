#pragma once

#include <iostream>
#include "BaseClass.h"

using namespace std;

class Derived: public Base
{
public:
	string DerivedClassString;

	Derived()
	{
		DerivedClassString = "Default string";
	}

	Derived(int NewValue): Base(NewValue)
	{
		DerivedClassString = "Default string";
	}

	~Derived()
	{

	}
};