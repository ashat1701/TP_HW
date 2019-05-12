#pragma once
#include <vector>
#include "points.h"
#include <random>

class Generator {
  std::vector<Point> points;
  std::default_random_engine generator;
  std::normal_distribution<> distribution;
 public:
  Generator(size_t count);
  std::vector<Point> getPoints();
};
