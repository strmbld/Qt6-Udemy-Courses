#ifndef BOX_H
#define BOX_H

#include "rectangle.h"


class Box
{
private:
    Rectangle m_rectangle;
    double m_height;

public:
    Box(double width, double length, double height);

    double get_volume()const;

};

#endif // BOX_H
