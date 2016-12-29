// BestSingleton.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Singleton.h"
#include <iostream>

using namespace std;

int main()
{
	BestSingleton& FirstTestSingletonObject = BestSingleton::Instance();
	cout << "Test int variable inside FIRST reference to singleton object: " << FirstTestSingletonObject.TestVariable << "\r\n";
	FirstTestSingletonObject.TestVariable += 1;
	cout << "+1\r\n";
	BestSingleton& SecondTestSingletonObject = BestSingleton::Instance();
	cout << "Test int variable inside SECOND reference to singleton object: " << SecondTestSingletonObject.TestVariable << "\r\n";
    return 0;
}

