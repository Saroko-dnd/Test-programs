#pragma once

//������� '�����' ��������� ��� ����� ����� ������
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

		//����������� ���������, ����� � �������� ����� ������ ����� ���� ���������� ��� � ������� ����������
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
