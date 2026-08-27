#include <iostream>

void doB()
{
    std::cout << "Simdi de B fonksiyonu calisiyor.\n";
}

void doA()
{
    std::cout << "A fonksiyonu calisiyor\n";
    doB();
    std::cout << "A fonksiyonu bitiyor.\n";
}

int main()
{
    std::cout << "main() fonksiyonu calisiyor.\n";
    doA();
    std::cout << "Tekrar main() fonksiyonu calisiyor.\n";

    return 0;
}