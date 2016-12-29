
#include "Singleton.h"
#include <iostream>

using namespace std;

BestSingleton& BestSingleton::Instance()
{
	static BestSingleton singleton;
	return singleton;
}

BestSingleton::BestSingleton()
{
	TestVariable = 99;
}

BestSingleton::~BestSingleton()
{
	cout << "Hello from best singleton destructor!\r\n";
	system("pause");
}