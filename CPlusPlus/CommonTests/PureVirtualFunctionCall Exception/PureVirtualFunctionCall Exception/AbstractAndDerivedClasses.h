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
			UsualFunction();
			//Произойдет исключение так как мы находимся в конструкторе абстрактного класса и UsualFunction() попробует вызвать чистую виртуальную функцию
							//(Справедливо и для деструкторов)
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
			UsualFunction();//Исключение не произойдет, так как здесь UsualFunction() вызывает уже реализацию чистой виртуальной функции для класса-наследника
		}
};
