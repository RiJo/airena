#include "point.h"

#include <math.h>

Point::Point(float x, float y) : x(x), y(y) {
    // nop
}

float Point::distance_to(float target_x, float target_y) const {
    float temp_x = target_x - x;
    float temp_y = target_y - y;
    return sqrt((temp_x * temp_x) + (temp_y * temp_y));
}

float Point::distance(Point p) const {
    return distance_to(p.x, p.y);
}