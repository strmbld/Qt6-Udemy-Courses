#include <iostream>


int main()
{
    std::string greeting = "Goodbye World!";
    int count = 7;

    std::cout << std::endl
              << greeting << std::endl
              << count << std::endl
              << "-----------" << std::endl
              << "sizeof()" << std::endl
              << "Size of int: " << sizeof(int) << std::endl
              << "Size of char: " << sizeof(char) << std::endl
                 << "Size of bool: " << sizeof(bool) << std::endl
                    << "Size of float: " << sizeof(float) << std::endl
                       << "Size of double: " << sizeof(double) << std::endl
                          << "Size of wchar_t: " << sizeof(wchar_t) << std::endl
                             << "-----------"<< std::endl
                                << "Type Modifiers" << std::endl
                                << "Size of short int: " << sizeof(short int) << std::endl
                                   << "Size of unsigned short int: " << sizeof(unsigned short int) << std::endl
                                      << "Size of unsigned int: " << sizeof(unsigned int) << std::endl
                                         << "Size of signed int: " << sizeof(signed int) << std::endl
                                            << "Size of long int: " << sizeof(long int) << std::endl
                                               << "Size of unsigned long long int: " << sizeof(unsigned long long int) << std::endl
                                                  << "Size of signed char: " << sizeof(signed char) << std::endl
                                                     << "Size of unsigned char: " << sizeof(unsigned char) << std::endl
                                                        << "Size of long double: " << sizeof(long double) << std::endl

    ;

    return 0;
}
