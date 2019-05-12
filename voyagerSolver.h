#pragma once
#include "graph.h"

class VoyagerSolver {
 public:
  virtual double solve() = 0;
  virtual std::vector<int> getAnswer() = 0;
  virtual ~VoyagerSolver() {}
  virtual void fromGraph(const Graph &graph) = 0;
};
