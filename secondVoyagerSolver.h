#pragma once
#include <vector>
#include <random>
#include "nativeVoyagerSolver.h"

class SecondVoyagerSolver : public VoyagerSolver {
  Graph graph;
  std::vector<int> answer;

 public:
  SecondVoyagerSolver(const Graph& graph);
  virtual double solve() override;
  std::vector<int> getAnswer() override;
  std::mt19937_64 rng;
  std::uniform_real_distribution<double> distr;
  double initialTemperature;
  double endTemperature;
  void fromGraph(const Graph &graph) override;
};
