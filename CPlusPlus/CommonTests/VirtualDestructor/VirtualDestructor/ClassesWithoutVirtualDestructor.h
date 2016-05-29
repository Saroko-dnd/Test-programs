#pragma once

#include <iostream>

using namespace std;

class BaseClass
{
	public:
		BaseClass()
		{
			cout << "Constructor of BaseClass " << endl;
		}

		~BaseClass()
		{
			cout << "Destructor of BaseClass " << endl;
		}
};

class DerivedClass : public BaseClass
{
	public:
		DerivedClass()
		{
			cout << "Constructor of DerivedClass " << endl;
		}

		~DerivedClass()
		{
			cout << "Destructor of DerivedClass " << endl;
		}

};