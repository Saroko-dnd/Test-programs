#pragma once

#include <iostream>

using namespace std;

class BaseClassWithVirtualDestructor
{
	public:
		BaseClassWithVirtualDestructor()
		{
			cout << "Constructor of BaseClassWithVirtualDestructor " << endl;
		}

		virtual ~BaseClassWithVirtualDestructor()
		{
			cout << "Destructor of BaseClassWithVirtualDestructor " << endl;
		}
};

class SecondDerivedClass : public BaseClassWithVirtualDestructor
{
	public:
		SecondDerivedClass()
		{
			cout << "Constructor of SecondDerivedClass " << endl;
		}

		~SecondDerivedClass()
		{
			cout << "Destructor of SecondDerivedClass " << endl;
		}
};