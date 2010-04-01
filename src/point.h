#ifndef _POINT_H_
#define _POINT_H_

class Point {
    public:
        float x;
        float y;

    protected:
        float distance_to(float, float) const;

    public:
        Point(float, float);
        float distance(Point) const;
};

#endif