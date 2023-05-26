#include <iostream>

#include "box.h"


int main()
{
    Box b(20.5, 10.0, 10.5);
    double vol = b.get_volume();

    std::cout << vol << std::endl;

    Rectangle r(25.5, 10.5);
    double area = r.get_area();

    std::cout << area << std::endl;

    return 0;
}
