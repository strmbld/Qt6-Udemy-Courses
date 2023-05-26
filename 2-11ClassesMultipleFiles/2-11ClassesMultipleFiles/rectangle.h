#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle
{
private:
    double m_width;
    double m_length;

public:
    Rectangle();
    Rectangle(double w, double l);

    void set_width(double width);
    void set_length(double length);

    double get_area()const;

};

#endif // RECTANGLE_H
