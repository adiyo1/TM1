description of the code:

for the function isConnected(g) i did an auxiliary function "isSim", that checking if the graph is unintentional or intentional-
if the graph is symmetrical it means that its not intentional, and we need to do bfs only once.
if the graph is intentional, we should do bfs as the number of vertices in the graph.
If the BFS reaches all edges in the graph then the graph is connected.


for the function shortestPath(g,start,end) i used belman ford algorithm (becouse we have edges with negative weight).
1. I create a distance array to store the shortest distances from the start node (start) to all other nodes.
2. i initialize all distances to positive infinity (INT_MAX).
3. I did relaxations
4. finding the shortest path

for the function isContainsCycle(g) i used dfs algorithm
1. Uses negativeCycle (assumed to check for cycles) and dfs (assumed to traverse the graph). Returns true if a cycle is found, false otherwise.
2. Checks for cycles using negativeCycle (important for negative weights).
3. Iterate through each node (i).
4. For each unvisited node, calls dfs to explore starting from i.
5. If dfs finds a cycle, returns true (with additional checks for specific cases).
6. If no cycle found after all nodes, returns false.

for the function isBipartite(g) first i Checked connectivity, If connected, it colors the graph using BFS:
1. Starts with an arbitrary node (color A).
2. Explores neighbors:
    1. Uncolored: assigns opposite color and adds to queue.
    2. Same color as current: detects cycle (not bipartite), returns "0".
3. If coloring finishes without a cycle, the graph is bipartite.

for the function negativeCycle(g) i use belman ford algorithm
1. Initializes distances (dist) to positive infinity (INT_MAX) and sets distance of the first node to 0.
2. Runs Bellman-Ford iterations (num_nodes - 1 times), For each node and its neighbors If an edge exists - Update the distance of the neighbor
if a shorter path is found through the current node.
3. Checks for negative cycles:
   1. Iterates again, looking for further distance updates.
   2. If any distance decreases in this iteration, it indicates a negative cycle, and the function returns true, else false.
