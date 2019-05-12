#include "firstVoyagerSolver.h"
#include <set>
#include <cstdint>

using std::vector;
using std::set;
using std::pair;

FirstVoyagerSolver::FirstVoyagerSolver(const Graph &graph) : graph(graph) {}

Graph getMinSpanningTree(Graph &graph) {
  const int INF = INT32_MAX;
  vector<int> min_edge(graph.verticesCount(), INF);
  vector<int> cur_end(graph.verticesCount(), -1);
  vector<bool> used(graph.verticesCount(), false);
  set<pair<int, int>> queue;
  queue.insert({0, 0});
  min_edge[0] = 0;
  Graph minSpanningTree(graph.getPoints(), false);
  while (!queue.empty()) {
    int curVertex = queue.begin()->second;
    used[curVertex] = true;
    if (cur_end[curVertex] != -1) {
        minSpanningTree.addEdge(Graph::Edge(curVertex, cur_end[curVertex], graph.getDistance(curVertex, cur_end[curVertex])));
        minSpanningTree.addEdge(Graph::Edge(cur_end[curVertex], curVertex, graph.getDistance(curVertex, cur_end[curVertex])));
    }
    queue.erase(queue.begin());
    for (auto neigh : graph.getNeighbors(curVertex)) {
      int to = neigh.to, cost = neigh.cost;
      if (cost < min_edge[to] && !used[to]) {
        queue.erase({min_edge[to], to});
        min_edge[to] = cost;
        cur_end[to] = curVertex;
        queue.insert({min_edge[to], to});
      }
    }
  }
  return minSpanningTree;
}

void doubleEdges(Graph &graph) {
    int verticesCount = graph.verticesCount();
    for (int i = 0; i < verticesCount; i++) {
        auto neigh = graph.getNeighbors(i);
        for (auto edge: neigh) {
            graph.addEdge(edge);
        }
    }
}

void dfs(int vertex, vector<bool>& used, vector<int>&cycle, Graph &graph) {
   if(!used[vertex])  {
       cycle.push_back(vertex);
       used[vertex] = 1;
   }
   for (auto &edge: graph.getNeighbors(vertex)) {
       if (!edge.color) {
           edge.color = 1;
           dfs(edge.to, used, cycle, graph);
       }
   }
}

double FirstVoyagerSolver::solve() {
    Graph minSpanningTree = getMinSpanningTree(graph);
    doubleEdges(minSpanningTree);
    vector<bool>used(graph.verticesCount());
    dfs(0, used, answer, minSpanningTree);
    int verticesCount = graph.verticesCount();
    double ans = 0;
    for (int i = 0; i < verticesCount - 1; i++)
        ans += graph.getDistance(answer[i], answer[i + 1]);
    ans += graph.getDistance(answer[0], answer[verticesCount - 1]);
    return ans;
}

vector<int> FirstVoyagerSolver::getAnswer() {
    return answer;
}

void FirstVoyagerSolver::fromGraph(const Graph &newGraph) {
    graph = newGraph;
    answer.clear();
}
