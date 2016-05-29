#pragma once

//ѕростой 'умный' указатель дл€ любых типов данных
template <typename PointerType>
class SmartPointer
{
	private:
		PointerType* HiddenObject;

	public:
		SmartPointer(PointerType* NewObjectToBeHidden)
		{
			HiddenObject = NewObjectToBeHidden;
		}

		~SmartPointer()
		{
			delete HiddenObject;
		}

		//ѕерегружаем операторы, чтобы с обьектом этого класса можно было обращатьс€ как с обычным указателем
		//*****************************************************************************************************
		PointerType* operator -> () const
		{
			return HiddenObject;
		}

		PointerType operator * () const
		{
			return *HiddenObject;
		}
		//*****************************************************************************************************
};
