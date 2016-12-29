// TypeConversions.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "BaseClass.h"

using namespace std;

int main()
{
	Base& TestReferenceToBaseClass = Base(5);
    return 0;
}

