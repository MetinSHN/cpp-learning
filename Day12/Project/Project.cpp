#include <iostream>

int main()
{
	std::cout << "Enter an integer : ";

	int x{};
	std::cin >> x;

	std::cout << "Double of " << x << " is : " << x * 2 << '\n';

	std::cout << "Triple of " << x << " is : " << x * 3 << '\n';

	return 0;
}