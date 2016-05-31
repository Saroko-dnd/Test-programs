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

		//!!!ѕришлось сделать friend перегрузку оператора less than дл€ set. “ак как перегрузку с одним параметром set не принимает!!!
		friend bool operator < (const MyKey& LeftKey, const MyKey& RightKey)
		{
			return LeftKey.KeyInt < RightKey.KeyInt;
		}
};
