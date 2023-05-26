#include "box.h"


Box::Box(double width, double length, double height) : m_rectangle(width, length), m_height(height) {}

double Box::get_volume()const { return m_rectangle.get_area() * m_height; }
