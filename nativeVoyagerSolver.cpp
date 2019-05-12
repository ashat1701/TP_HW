#include "nativeVoyagerSolver.h"
#include <algorithm>
using std::vector;

NativeVoyagerSolver::NativeVoyagerSolver(const Graph &graph) : graph(graph) {}

double NativeVoyagerSolver::solve() {
  vector<int> perm(graph.verticesCount());
  for (int i = 0; i < perm.size(); i++) perm[i] = i;
  int verticesCount = graph.verticesCount();
  double cur_ans = -1;
  do {
    double ans = 0;
    for (int i = 0; i < verticesCount - 1; i++) {
      ans += graph.getDistance(perm[i], perm[i + 1]);
    }
    ans += graph.getDistance(perm[0], perm[verticesCount - 1]);
    if (cur_ans < 0 || ans < cur_ans) {
      cur_ans = ans;
      answer = perm;
    }
  } while(next_permutation(begin(perm), end(perm)));
  return cur_ans;
}

vector<int> NativeVoyagerSolver::getAnswer() { return answer; }

void NativeVoyagerSolver::fromGraph(const Graph &newGraph) {
    graph = newGraph;
}
