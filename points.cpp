#include <cmath>
#include "points.h"

Point::Point(double x, double y): x(x), y(y) {}

double dist(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

