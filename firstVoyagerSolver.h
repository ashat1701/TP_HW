#pragma once
#include <vector>
#include "nativeVoyagerSolver.h"

class FirstVoyagerSolver : public VoyagerSolver {
  Graph graph;
  std::vector<int> answer;

 public:
  FirstVoyagerSolver(const Graph& graph);
  virtual double solve() override;
  std::vector<int> getAnswer() override;
  void fromGraph(const Graph &graph) override;
};
