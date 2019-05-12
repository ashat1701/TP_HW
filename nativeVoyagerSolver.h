#pragma once
#include "voyagerSolver.h"

class NativeVoyagerSolver : public VoyagerSolver {
  Graph graph;
  std::vector<int> answer;

 public:
  NativeVoyagerSolver(const Graph &graph);
  std::vector<int> getAnswer() override;
  double solve() override;
  void fromGraph(const Graph &graph) override;
};
