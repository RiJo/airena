#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "point.h"

struct Vector : private Point {
    public:
        Vector(float, float);
        float length() const;
        float angle() const;
};

#endif