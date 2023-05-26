#include <iostream>


class Rectangle
{
private:
    double m_width;
    double m_height;

public:
    void set_width(double width);
    void set_height(double height);
    double get_area()const;
};

void Rectangle::set_width(double width) { m_width = width; }
void Rectangle::set_height(double height) { m_height = height; }
double Rectangle::get_area()const { return m_width * m_height; }


int main()
{
    Rectangle r;
    r.set_width(10.1);
    r.set_height(20.2);

    double area = r.get_area();

    std::cout << area << std::endl;

    return 0;
}
