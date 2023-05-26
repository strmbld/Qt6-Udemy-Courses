#include <iostream>

// Declaration - declarations are used by compiler at pre-processing/compilation stage
double add(double a, double b);

int main()
{
    double res = add(10.3, 11.7);

    std::cout << res << std::endl;

    return 0;
}

// Implementation - implementations are used by linker at linking stage
// double add(double a, double b) { return a + b; }
