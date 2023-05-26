#include <iostream>


class Rectangle
{
private:
    double width;
    double length;

public:
    Rectangle();
    Rectangle(double w, double l);

    void set_width(double width);
    void set_length(double length);

    double get_area()const;

};

Rectangle::Rectangle() {}
// Rectangle::Rectangle(double width, double length) { this->width = width; this->length = length; } // or name fields like m_width, m_length
Rectangle::Rectangle(double width, double length) : width(width), length(length) {}

void Rectangle::set_width(double width) { this->width = width; } // or name fields like m_width, m_length
void Rectangle::set_length(double length) { this->length = length; }
double Rectangle::get_area()const { return width * length; }

class Box
{
private:
    Rectangle rectangle;
    double height;

public:
    Box(double width, double length, double height);

    double get_volume()const;

};

Box::Box(double width, double length, double height) : rectangle(width, length), height(height) {}

double Box::get_volume()const { return rectangle.get_area() * height; }


int main()
{
    Rectangle r;
    r.set_width(20.22);
    r.set_length(10.5);
    double area = r.get_area();
    std::cout << area << std::endl;

    Rectangle r2(20.22, 10.5);
    double area2 = r2.get_area();
    std::cout << area2 << std::endl;

    Box b(20, 5, 10);
    double v = b.get_volume();
    std::cout << v << std::endl;

    return 0;
}
