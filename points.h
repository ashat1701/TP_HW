#pragma once
class Point {
    double x, y;
    friend double dist(const Point &a, const Point &b);
    public:
    Point(double x, double y);
};

double dist(const Point &a, const Point &b);
