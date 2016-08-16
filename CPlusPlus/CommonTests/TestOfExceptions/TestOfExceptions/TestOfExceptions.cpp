// TestOfExceptions.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	try
	{
		try
		{
			cout << "Enter 1 for 'String exception' or 2 for 'Int exception':" << endl;
			int UserNumber = 0;
			cin >> UserNumber;
			if (UserNumber == 1)
			{			
				throw new string("string");
			}
			else
			{
				throw 5;
			}
		}
		catch (string * StringException)
		{
			cout << "Catch for string exception (throw without arguments)" << endl;
			throw;
		}
		catch (int IntException)
		{
			cout << "Catch for int exception (throw without arguments)" << endl;
			throw;
		}
	}
	catch (string * SecondStringException)
	{
		cout << "Second catch for string exception" << endl;
	}
	catch (int SecondIntException)
	{
		cout << "Second catch for int exception" << endl;		
	};

	system("Pause");

    return 0;
}

