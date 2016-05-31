// SetTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "SetKeyClass.h"
#include <set>

using namespace std;

int main()
{
	set<MyKey> MySetOfInt;

	MyKey TestObject(5);

	MySetOfInt.insert(TestObject);

	system("Pause");
    return 0;
}

