#include <iostream>


inline int add(int a, int b) { return a + b; }

inline double add(double a, double b) { return a + b; }

inline void greet() { std::cout << "Goodbye!" << std::endl; }

int main()
{
    int a = 3;
    int b = 7;
    int c = 34;

    int result = add(a, b);
    int result1 = add(a, c);

    std::cout << "a + b = " << result << std::endl
              << "a + c = " << result1 << std::endl
                 ;

    greet();

    double x = 3.8;
    double y = 4.3;
    double result2 = add(x, y);

    std::cout << result2 << std::endl;

    return 0;
}
