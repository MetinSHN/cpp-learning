#include <iostream>

int add(int x, int y, int z);

int main()
{
	std::cout << "3, 4 ve 5'in toplami = " << add(3, 4, 5);
}

int add(int x, int y, int z)
{
	return x + y + z;
}