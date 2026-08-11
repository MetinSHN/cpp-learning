#include <iostream>

int main()
{
    [[maybe_unused]] double pi{ 3.14159 };  // Don't complain if pi is unused
    [[maybe_unused]] double gravity{ 9.8 }; // Don't complain if gravity is unused
    [[maybe_unused]] double phi{ 1.61803 }; // Don't complain if phi is unused

    std::cout << pi << '\n';
    std::cout << phi << '\n';


    int a;
    int b = 4;
    int c(5.4); // 5 olarak alacak
//  int x { 4.5 }; yazsaydım hata verecekti çünkü bu yöntemde daraltma özelliği yasaklı. Bu yüzden de en çok tercih edilen yöntem.
    int d{ 6 };
    int e{};

    std::cout << b << '\n';
    std::cout << c << '\n';
    std::cout << d << '\n';

    // Derleyici değişken kullanılmadığı için uyarmayacak

    return 0;
}