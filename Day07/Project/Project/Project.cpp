#include <iostream>

void doNothing(int&)
{
}

int main()
{
	int x; // henüz başlatmadık bir değeri yok.

	doNothing(x);

	std::cout << x << '\n'; // Belli bir değer olmadığı için rastgele bir değer atayacak lakin Visual Code'da hata veriyor çünkü bir değer vermedik.

	std::cout << sizeof(int) << '\n';

	return 0;
}