#pragma once

#include <type_traits>
#include <iostream>

using namespace std;

template<typename FirstNumber, typename SecondNumber>
class Calculator
{

	static_assert(std::is_arithmetic<FirstNumber>::value && std::is_arithmetic<SecondNumber>::value, "Calculator object accepts only numbers!");// only arithmetic types allowed

private:
	FirstNumber CurrentFirstNumber;
	SecondNumber CurrentSecondNumber;

public:

	template<typename FirstNumberCopy = FirstNumber, typename SecondNumberCopy = SecondNumber>// only for <int,int> case
	typename std::enable_if<std::is_same<FirstNumberCopy, int>::value && std::is_same<SecondNumberCopy, int>::value, double>::type
	Sum()
	{
		cout << "Sum() for int types:\r\n";
		cout << CurrentFirstNumber << " + " << CurrentSecondNumber << " = ";
		return CurrentFirstNumber + CurrentSecondNumber;
	}

	template<typename FirstNumberCopy = FirstNumber, typename SecondNumberCopy = SecondNumber>// all cases except <int,int>
	typename std::enable_if<!std::is_same<FirstNumberCopy, int>::value || !std::is_same<SecondNumberCopy, int>::value, double>::type
	Sum()
	{
		cout << "Sum() for all arithmetic types (except int):\r\n";
		cout << "'" << CurrentFirstNumber << "'" << " + " << CurrentSecondNumber << " = ";
		return CurrentFirstNumber + CurrentSecondNumber;
	}

	Calculator(FirstNumber NewFirstNumber, SecondNumber NewSecondNumber)
	{
		CurrentFirstNumber = NewFirstNumber;
		CurrentSecondNumber = NewSecondNumber;
	}
};