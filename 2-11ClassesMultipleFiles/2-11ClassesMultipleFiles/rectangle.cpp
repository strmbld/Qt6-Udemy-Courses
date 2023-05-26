#include "rectangle.h"


Rectangle::Rectangle() {}
Rectangle::Rectangle(double width, double length) : m_width(width), m_length(length) {}

void Rectangle::set_width(double width) { m_width = width; } // or name fields like m_width, m_length
void Rectangle::set_length(double length) { m_length = length; }
double Rectangle::get_area()const { return m_width * m_length; }
