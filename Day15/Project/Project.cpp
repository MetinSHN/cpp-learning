#include <iostream>

int getFive()
{
	return 5;
}

int main()
{
	int num1{ getFive()};
	int num2{ getFive() };
	std::cout << num1 << " ve " << num2 << " sayilarinin toplami : " << num1 + num2;

	return 0;
}