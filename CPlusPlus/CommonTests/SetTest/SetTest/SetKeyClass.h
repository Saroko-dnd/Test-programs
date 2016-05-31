#pragma once

class MyKey
{
	private:
		int KeyInt;

	public:
		MyKey(int NewKeyValue)
		{
			KeyInt = NewKeyValue;
		}

		//!!!�������� ������� friend ���������� ��������� less than ��� set. ��� ��� ���������� � ����� ���������� set �� ���������!!!
		friend bool operator < (const MyKey& LeftKey, const MyKey& RightKey)
		{
			return LeftKey.KeyInt < RightKey.KeyInt;
		}
};
