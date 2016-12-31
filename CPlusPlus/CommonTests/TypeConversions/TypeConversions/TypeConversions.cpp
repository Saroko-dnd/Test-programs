// TypeConversions.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "BaseClass.h"
#include "DerivedClass.h"

using namespace std;

int main()
{
	Base& TestReferenceToBaseClass = Base(5);
	Base& ReferenceToBaseWithDerivedInside = Derived(10);
	Base* TestPointerToBaseClass = new Base(5);
	Base* PointerToBaseWithDerivedInside = new Derived(10);
	Derived& TestReferenceToDerivedClass = Derived(10);
	Derived* TestPointerToDerivedClass = new Derived(10);

	try
	{
		Base& DynamicCastResult = dynamic_cast <Base&> (TestReferenceToDerivedClass);
		cout << "Derived& was successfully casted to Base& (dynamic_cast)\r\n";
		cout << "Test int inside new Base&: " << DynamicCastResult.CurrentValue << "\r\n";

	}
	catch(...)
	{
		cout << "BAD CAST exception was thrown during attempt to convert Derived& to Base&\r\n";
	}

	cout << "\r\n";

	try
	{
		Derived& DynamicCastResult = dynamic_cast <Derived&> (TestReferenceToBaseClass);
		cout << "Base& was successfully casted to Derived& (dynamic_cast)\r\n";
		cout << "Test int inside new Derived&: " << DynamicCastResult.CurrentValue << "\r\n";
	}
	catch (...)
	{
		cout << "BAD CAST exception was thrown during attempt to convert Base& to Derived&\r\n";
	}

	cout << "\r\n";

	try
	{
		Derived& DynamicCastResult = dynamic_cast <Derived&> (ReferenceToBaseWithDerivedInside);
		cout << "Base& (with Derived& inside) was successfully casted to Derived& (dynamic_cast)\r\n";
		cout << "Test int inside new Derived&: " << DynamicCastResult.CurrentValue << "\r\n";
	}
	catch (...)
	{
		cout << "BAD CAST exception was thrown during attempt to convert Base& (with Derived& inside) to Derived&\r\n";
	}

	cout << "\r\n";

	Base* DynamicCastResultPointerToBase = dynamic_cast <Base*> (TestPointerToDerivedClass);
	if (DynamicCastResultPointerToBase)
	{
		cout << "Derived* was successfully casted to Base* (dynamic_cast)\r\n";
		cout << "Test int inside new Base&: " << DynamicCastResultPointerToBase->CurrentValue << "\r\n";
	}
	else
	{
		cout << "dynamic_cast failed to cast Derived* to Base*\r\n";
	}

	cout << "\r\n";

	Derived* DynamicCastResultPointerToDerived = dynamic_cast <Derived*> (TestPointerToBaseClass);
	if (DynamicCastResultPointerToDerived)
	{
		cout << "Base* was successfully casted to Derived* (dynamic_cast)\r\n";
		cout << "Test int inside new Derived*: " << DynamicCastResultPointerToDerived->CurrentValue << "\r\n";
	}
	else
	{
		cout << "dynamic_cast failed to cast Base* to Derived*\r\n";
	}

	cout << "\r\n";

	Derived* SecondDynamicCastResultPointerToDerived = dynamic_cast <Derived*> (PointerToBaseWithDerivedInside);
	if (SecondDynamicCastResultPointerToDerived)
	{
		cout << "Base* (with Derived* inside) was successfully casted to Derived* (dynamic_cast)\r\n";
		cout << "Test int inside new Derived*: " << SecondDynamicCastResultPointerToDerived->CurrentValue << "\r\n";
	}
	else
	{
		cout << "dynamic_cast failed to cast Base* (with Derived* inside) to Derived*\r\n";
	}

	delete TestPointerToBaseClass;
	delete TestPointerToDerivedClass;
	delete PointerToBaseWithDerivedInside;

	cout << "\r\n";
	system("pause");

    return 0;
}

