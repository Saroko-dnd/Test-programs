#pragma once

class BestSingleton
{
	public:
		static BestSingleton& Instance();
		int TestVariable;
	// Other non-static member functions
	private:
		BestSingleton();// Private constructor
		~BestSingleton();
		BestSingleton(const BestSingleton&);                 // Prevent copy-construction
		BestSingleton& operator=(const BestSingleton&);      // Prevent assignment
};