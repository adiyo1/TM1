#include "Algorithms.hpp"

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

namespace ariel
{

	Algorithms::Algorithms() {}

	bool Algorithms::bfs(Graph graph, size_t start)
	{
		// Get the number of nodes from the Graph object
		size_t num_nodes = graph.get_size();

		// Create a visited vector to track visited nodes
		vector<bool> visited(num_nodes, false);

		// Queue to store nodes for BFS exploration
		queue<size_t> q;

		// Mark the starting node as visited and enqueue it
		visited[start] = true;
		q.push(start);

		while (!q.empty())
		{
			// Dequeue a node from the queue
			size_t current_node = q.front();
			q.pop();

			// Explore all unvisited neighbors of the current node
			// for (size_t neighbor : graph.getNei()[current_node]) {
			size_t num_nodes = graph.get_size(); // Assuming get_size() exists

			for (size_t neighbor = 0; neighbor < num_nodes; ++neighbor)
			{
				if (graph.getNei()[current_node][neighbor] >= 1)
				{
					// Process neighbor (code to be executed for each neighbor)
					if (!visited[neighbor])
					{
						visited[neighbor] = true;
						q.push(neighbor);
					}
				}
			}
		}

		// Check if all nodes are visited (connected)
		for (bool v : visited)
		{
			if (!v)
			{
				return false; // Unvisited node found, graph is not connected
			}
		}

		return true; // All nodes visited, graph is connected
	}

	string Algorithms::isConnected(Graph g)
	{
		cout << "graph size is: " << g.get_size() << endl;

		if (g.isSim() == false)
		{
			if (bfs(g, 0))
			{
				return "1";
			}
			return "0";
		}
		else
		{
			int flag = 0;
			for (size_t i = 0; i < g.get_size(); i++)
			{
				if (bfs(g, i))
				{
					flag = 1;
				}
			}
			if (flag == 0)
			{
				return "0";
			}
			return "1";
		}
	}

	bool Algorithms::dfs(Graph graph, size_t node, vector<bool> &visited, vector<bool> &inStack)
	{
		visited[node] = true;
		inStack[node] = true; // Mark node as being explored in the current DFS call

		// Explore unvisited neighbors
		for (size_t neighbor = 0; neighbor < graph.get_size(); ++neighbor)
		{
			// for (size_t neighbor : graph.getNeighbors(node)) {
			if (!visited[neighbor])
			{
				if (dfs(graph, neighbor, visited, inStack))
				{				 // Recursive call
					return true; // Cycle found
				}
			}
			else if (inStack[neighbor])
			{ // Back edge detected (cycle)
				return true;
			}
		}

		// Leaving this node (no cycle found in this branch)
		inStack[node] = false;
		return false; // No cycle found
	}

	// string Algorithms::isContainsCycle(Graph graph) {
	// 	size_t num_nodes = graph.get_size();

	// 	// Create visited and inStack vectors to track exploration
	// 	vector<bool> visited(num_nodes, false);
	// 	vector<bool> inStack(num_nodes, false);

	// 	// Start DFS from each node (handle disconnected graphs)
	// 	for (size_t i = 0; i < num_nodes; ++i) {
	// 		if (!visited[i]) {
	// 			if (dfs(graph, i, visited, inStack)) {
	// 				return "true"; // Cycle found during exploration
	// 			}
	// 		}
	// 	}

	// 	return "false"; // No cycle found in the entire graph
	// 	}

	bool Algorithms::negetiveEdge(Graph graph)
	{
		for (size_t i = 0; i < graph.get_size(); i++)
		{
			for (size_t j = 0; j < graph.get_size(); j++)
			{
				if (graph.get_nei(i, j) < 0)
					return true;
			}
		}
		return false;
	}
	string Algorithms::shortestPath(Graph g, int x, int y)
	{
		return "wvw";
	}

	// string Algorithms::isContainsCycle(Graph g) {
	// 	vector<vector<int>> adjacency_list = convert_graph_to_adjacency_list(g);
	// 	//adjacency_list[0]=true;

	//         return "wvw";
	// }
	string Algorithms::isBipartite(Graph g)
	{
		return "wvw";
	}

	//  bool Algorithms:: dfs(Graph& graph, size_t node, vector<bool>& visited, vector<bool>& inStack, stack<size_t>& cycle_path) {
	// 	visited[node] = true;
	// 	inStack[node] = true;
	// 	cycle_path.push(node);  // Add current node to the potential cycle path

	// 	// Explore unvisited neighbors
	// 	for (size_t neighbor = 0; neighbor < graph.get_size(); ++neighbor) {
	// 		if (!visited[neighbor]) {
	// 			if (dfs(graph, neighbor, visited, inStack, cycle_path)) {
	// 				return true; // Cycle found
	// 			}
	// 		} else if (inStack[neighbor]) { // Back edge detected (cycle)
	// 			cycle_path.push(neighbor);  // Add neighbor to the cycle path
	// 			return true; // Cycle found
	// 		}
	// 	}

	// 	// Leaving this node (no cycle found in this branch)
	// 	inStack[node] = false;
	// 	cycle_path.pop();  // Remove current node from potential path
	// 	return false; // No cycle found
	// }
	 string Algorithms::constructCycleString(stack<size_t> cycle_path)
	{
		string cycle_str;
		while (!cycle_path.empty())
		{
			size_t top = cycle_path.top();
			cycle_path.pop();
			cycle_str = to_string(top) + (cycle_str.empty() ? "" : "->") + cycle_str;
		}
		return cycle_str;
	}

	string Algorithms::isContainsCycle(Graph graph)
	{
		// static string findAndPrintCycle(Graph& graph) {
		size_t num_nodes = graph.get_size();

		// Visited and inStack vectors for tracking exploration
		vector<bool> visited(num_nodes, false);
		vector<bool> inStack(num_nodes, false);
		stack<size_t> cycle_path; // Stack to store nodes in the cycle path

		// Start DFS from each node (handle disconnected graphs)
		for (size_t i = 0; i < num_nodes; ++i)
		{
			if (!visited[i])
			{
				if (dfs(graph, i, visited, inStack, cycle_path))
				{
					return constructCycleString(cycle_path); // Construct and return cycle string
				}
			}
		}

		return "No cycle found"; // No cycle in the entire graph
	}

	bool Algorithms:: dfs(Graph graph, size_t node, vector<bool> visited, vector<bool> &inStack, stack<size_t> &cycle_path)
	{
		visited[node] = true;
		inStack[node] = true;
		cycle_path.push(node); // Add current node to the potential cycle path

		// Explore unvisited neighbors
		//for (size_t neighbor = 0; neighbor < graph.get_size(); ++neighbor)
		for (size_t neighbor = 0; neighbor < graph.get_size(); ++neighbor){
				{
					if (graph.get_nei(node,neighbor) == 1)
					{
		
						if (!visited[neighbor])
						{
							if (dfs(graph, neighbor, visited, inStack, cycle_path))
							{
								return true; // Cycle found
							}
						}
						else if (inStack[neighbor])
						{							   // Back edge detected (cycle)
							cycle_path.push(neighbor); // Add neighbor to the cycle path
							return true;			   // Cycle found
						}
					}
				}
			
		}
		// Leaving this node (no cycle found in this branch)
        inStack[node] = false;
        cycle_path.pop();  // Remove current node from potential path
        return false; // No cycle found
	}

}