#include <iostream>


int main()
{
    int a = 25;
    int b = 20;

    std::cout << "----- Math Operators -----" << std::endl
              << "a == " << a << "; b == " << b << ";" << std::endl
              << "a + b = " << a + b << std::endl
                 << "a - b = " << a - b << std::endl
                    << "a * b = " << a * b << std::endl
                       << "a / b = " << (double)a / b << std::endl
                          << "a % b = " << a % b << std::endl
                             ;

    // something about if/else

    std::string decision = a == b ? "equal" : "not equal";
    std::cout << decision << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cout << "Goodbye World! " << i + 1 << std::endl;
    }

    int count = 0;
    while (count != 10) {
        std::cout << "same but in while loop " << count + 1 << std::endl;
        count += 1;
    }

    return 0;
}
