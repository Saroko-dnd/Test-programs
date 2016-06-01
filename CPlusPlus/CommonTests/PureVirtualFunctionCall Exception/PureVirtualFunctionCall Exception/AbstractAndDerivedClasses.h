#pragma once

#include <iostream>

using namespace std;

class BaseAbstractClass
{
	public:
		virtual void SecondPureVirtualFunction() = 0;
		virtual void PureVirtualFunction() = 0;

		void UsualFunction()
		{
			cout << "This is usual function" << endl;
			SecondPureVirtualFunction();
		}

		
		BaseAbstractClass()
		{
			UsualFunction();//���������� ���������� ��� ��� �� ��������� � ������������ ������������ ������ � UsualFunction() ��������� ������� ������ ����������� �������
							//(����������� � ��� ������������)
		}
};

class DerivedClass : public BaseAbstractClass
{
	public:

		virtual void SecondPureVirtualFunction()
		{
			cout << "This is second realized function" << endl;
		}

		virtual void PureVirtualFunction()
		{
			cout << "This is first realized function" << endl;
			UsualFunction();//���������� �� ����������, ��� ��� ����� UsualFunction() �������� ��� ���������� ������ ����������� ������� ��� ������-����������
		}
};
