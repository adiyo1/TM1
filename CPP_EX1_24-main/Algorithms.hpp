#include <iostream>
#include "Graph.hpp"

namespace ariel {
    class Algorithms {
        public:
            static int isConnected(Graph g);
            static string shortestPath(Graph g, int x, int y);
            static string isContainsCycle(Graph g);
            static string isBipartite(Graph g);
    };
}