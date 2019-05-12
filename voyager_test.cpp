#include <chrono>
#include <iostream>
#include <thread>
#include "firstVoyagerSolver.h"
#include "secondVoyagerSolver.h"
#include "generator.h"
#include "nativeVoyagerSolver.h"
using std::cout;

void testSolver(VoyagerSolver &solver) {
for (int count = 3; count < 8; count++) {
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "N = " << count << std::endl;
    Generator gen(count);
    for (int i = 0; i < 2; i++) {
      cout << "------------------------------------------------" << std::endl; 
      Graph graph(gen.getPoints());
      solver.fromGraph(graph);
      NativeVoyagerSolver true_solver(graph);
      double true_ans = true_solver.solve();
      cout << "True cycle len - " << true_ans << std::endl;
      cout << "True cycle - ";
      for (auto it : true_solver.getAnswer()) cout << it + 1 << '-';
      cout << true_solver.getAnswer()[0] + 1 << std::endl;
      double ans = solver.solve();
      cout << "Our cycle len - " << ans << std::endl;
      cout << "Our cyle - ";
      for (auto it : solver.getAnswer()) cout << it + 1 << '-';
      cout << solver.getAnswer()[0] + 1 << std::endl;
      cout << "Ratio - " << ans / true_ans << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  }

}
int main(int argc, char** argv) {
  std::cout << "MST solver vs native solver." << std::endl;
  FirstVoyagerSolver firstSolver(Graph({}));
  testSolver(firstSolver);
  cout << "----------------------------------------------------" << std::endl;
  std::cout << "SimulatedAnnealing solver vs native solver" << std::endl;
  SecondVoyagerSolver secondSolver(Graph({}));
  testSolver(secondSolver);
}

