#include "graph.h"
#include <tuple>
using std::vector;

Graph::Edge::Edge(int from, int to, double cost) : from(from), to(to), cost(cost), color(0) {}

bool Graph::Edge::operator<(const Graph::Edge &a) {
  return std::make_tuple(cost, from, to) < std::make_tuple(a.cost, a.from, a.to);
}

Graph::Graph(const vector<Point> &points, bool isFull) : points(points) {
  graph.resize(points.size());
  if (isFull) {
    for (int i = 0; i < points.size(); i++)
      for (int j = 0; j < points.size(); j++) {
        if (i == j) continue;
        graph[i].emplace_back(i, j, dist(points[i], points[j]));
      }
  }
}

vector<Graph::Edge> &Graph::getNeighbors(int vertex) {
  return graph[vertex];
}

size_t Graph::verticesCount() const{ return graph.size(); }

double Graph::getDistance(int vertex1, int vertex2) const {
  return dist(points[vertex1], points[vertex2]);
}

void Graph::addEdge(Graph::Edge e) {
    graph[e.from].emplace_back(e);
}
const vector<Point>& Graph::getPoints() const {
    return points;
}
