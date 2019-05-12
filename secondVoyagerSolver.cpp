#include "secondVoyagerSolver.h"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <random>
#include <set>
#include <iostream>

using std::pair;
using std::set;
using std::vector;

double decreaseTemperature(double initialTemperature, int step) {
  return initialTemperature * 0.1 / step;
}

double transitionProbability(double dE, double T) { return exp(-dE / T); }

bool isTransition(double probability, std::mt19937_64 &rng,
                  std::uniform_real_distribution<double> &distr) {
  double value = distr(rng);
  return value <= probability;
}

vector<int> generateCandidate(const vector<int> &perm, std::mt19937_64 &rng) {
  vector<int> ans(perm);
  int i = (rng() % (1LL * ans.size()));
  int j = (rng() % (1LL * ans.size()));
  if (i > j) std::swap(i, j);
  reverse(ans.begin() + i, ans.begin() + j);
  return ans;
}

double calcLength(const vector<int> &perm, const Graph &graph) {
  double ans = 0;
  for (int i = 1; i < perm.size(); i++) {
    ans += graph.getDistance(perm[i - 1], perm[i]);
  }
  ans += graph.getDistance(perm[perm.size() - 1], perm[0]);
  return ans;
}

double SecondVoyagerSolver::solve() {
  vector<int> perm;
  int count = graph.verticesCount();
  perm.resize(count);
  for (int i = 0; i < count; i++) {
    perm[i] = i;
  }

  std::random_shuffle(begin(perm), end(perm));
  double currentTemperature = initialTemperature;
  double currentAnswer = calcLength(perm, graph);
  int iteration = 1;
  while (currentTemperature >= endTemperature) {
    vector<int> candidate = generateCandidate(perm, rng);
    double candidateLength = calcLength(candidate, graph);
    if (candidateLength < currentAnswer) {
      currentAnswer = candidateLength;
      perm = candidate;
    } else {
      double prob = transitionProbability(candidateLength - currentAnswer,
                                          currentTemperature);
      if (isTransition(prob, rng, distr)) {
        currentAnswer = candidateLength;
        perm = candidate;
      }
    }
    currentTemperature = decreaseTemperature(initialTemperature, iteration);
    iteration++;
  }
  answer = perm;
  return currentAnswer;
}

vector<int> SecondVoyagerSolver::getAnswer() { return answer; }

SecondVoyagerSolver::SecondVoyagerSolver(const Graph &graph)
    : graph(graph), distr(0, 1) {
  uint64_t timeSeed =
      std::chrono::high_resolution_clock::now().time_since_epoch().count();
  std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32)};
  rng.seed(ss);
  initialTemperature = 10;
  endTemperature = 0.0001;
}

void SecondVoyagerSolver::fromGraph(const Graph &newGraph) { graph = newGraph; }
