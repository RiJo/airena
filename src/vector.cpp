#include "vector.h"

#include <math.h>

Vector::Vector(float x, float y) : Point(x, y) {
    // nop
}

float Vector::length() const {
    return distance_to(0, 0);
}

float Vector::angle() const {
    return atan2(y, x);
}