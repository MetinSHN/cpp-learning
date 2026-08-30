#include <iostream>

void doubleNumber(int num)
{
    std::cout << "Double of " << num << " is : " << num * 2;
}

int getValueFromUser() 
{
    std::cout << "Enter an integer : ";
    int num{};
    std::cin >> num;
    return num;
}

int main()
{
    doubleNumber(getValueFromUser());
}