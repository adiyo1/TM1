#include "Algorithms.hpp"

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace ariel {
   
        int Algorithms::isConnected(Graph g) {
        
            void bfs(vector<vector<int>>& graph, vector<bool>& visited, int start) {
            queue<int> q;
            q.push(start);
            visited[start] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
                }
            }
            }

            bool is_graph_connected_bfs(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<bool> visited(n, false);

            bfs(graph, visited, 0);

            for (bool v : visited) {
                if (!v) {
                return 0;
                }
            }

            return 1;
            }
        }
        string Algorithms::shortestPath(Graph g, int x, int y) {

        }
        string Algorithms::isContainsCycle(Graph g) {

        }
        string Algorithms::isBipartite(Graph g) {

        }
}