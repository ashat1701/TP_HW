#include "generator.h"
#include <chrono>
#include <random>
using std::vector;
Generator::Generator(size_t count) {
  unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count();
  generator = std::default_random_engine(seed);
  distribution = std::normal_distribution<>(0.0, 1.0);
  points.resize(count, {0,0});
}

vector<Point> Generator::getPoints() {
    for (int i = 0; i < points.size(); i++)                    
      points[i] = Point(distribution(generator), distribution(generator));
    return points;
}

