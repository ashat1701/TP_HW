#pragma once
#include <vector>
#include <cstddef>
#include "points.h"

class Graph {
 public:
  struct Edge {
    int from, to;
    double cost;
    bool color;
    Edge(int from, int to, double cost);
    bool operator<(const Edge &a);
  };
 private:
  std::vector<std::vector<Edge> > graph;
  std::vector<Point> points;
 public:
  Graph(const std::vector<Point> &points, bool isFull=true);
  void addEdge(Edge e);
  size_t verticesCount() const;
  const std::vector<Point>& getPoints() const;
  double getDistance(int vertex1, int vertex2) const;
  std::vector<Edge>& getNeighbors(int vertex);
};

