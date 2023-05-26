#include <iostream>


int main()
{
    std::cout << "std::cout output" << std::endl;

    std::cerr << "std::cerr output" << std::endl;

    std::clog << "std::clog output" << std::endl;

    std::string name;
    std::cout << "Enter name: " << std::endl;
    std::cin >> name;
    std::cout << "Print name var via std::cout: " << name << std::endl;

    return 0;
}
