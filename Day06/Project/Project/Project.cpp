#include <iostream>

int main()
{
	// std::cout komutunun ve << operatorunun kullanim sekilleri 

	std::cout << "std::cout komutunu" << " ogrenmeye hos geldin. ";
	int x{ 5 }, y{ 6 }, z{ 8 };
	std::cout << x << " " << y << " ";
	std::cout << "Bastaki ikili sirayla x ve y degiskenlerinin degeriydi z degiskeninin degeri ise : " << z;

	// simdi std::endl komutuna geçiyoruz

	std::cout << std::endl << "Bu satir diger satirdan ayri olan bir satir." << std::endl;

	// \n özel sembolü

	std::cout << "Bu da ondan" << '\n';
	std::cout << "daha pratik olan" << "\n";
	std::cout << "ozel bir semboldur\n";
	std::cout << "bu std::endl'e gore daha pratik ve hizlidir\n";

	// std::cin

	std::cout << "Simdi ise bir rakam girin: ";

	int a{};

	std::cin >> a;

	std::cout << a << " rakamini girdiniz.\n";

	std::cout << "Simdi ise 2 rakam girin arada boslukla ";

	int b{}; // 1. rakamı çekiyoruz
	int c{}; // 2. rakamı çekiyoruz

	std::cin >> b >> c; // rakamları giriyoruz.

	std::cout << b << " ve " << c << " rakamlarini girdiniz.";

	std::cout << "\nBir kere daha 2 rakam girin. ";
	int d{};
	std::cin >> d;

	int e{};
	std::cin >> e;

	std::cout << "Su 2 rakami girdiniz: " << d << " " << e << '\n';

	return 0;
}