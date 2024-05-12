#include "Graph.hpp"

using namespace std;


namespace ariel {

    Graph::Graph() {}
    vector<vector<int>>& Graph::getNei(){
        return this->_nei;
    }

    void Graph::loadGraph(vector<vector<int>> graph) {
        this->_nei = graph;
        this->_isSim =this->isSim();
    }
    
    size_t Graph::get_size() {
        // Check if the adjacency matrix has been loaded
        if (this->_nei.empty()) {
            return 0; // Return 0 if no graph loaded
        } else {
            // Return the number of rows (assuming square matrix)
            return this->_nei.size();
        }
    }
    void Graph::printGraph() {
        
        int edges=0;
        // for(int neighbor=0; neighbor<this->get_size();neighbor++)
        // {
        //     cout << neighbor << ", ";
        // }
        // cout << endl;
        for (size_t i = 0; i < this->get_size(); i++)
		{
			for (size_t j = 0; j < this->get_size(); j++)
			{
				if (this->get_nei(i, j) != 0)
					edges++;
			}
		}
        cout << "Graph with " << this->get_size() << " vertices and " << edges << " edges." << endl;

    }
    
    

    int Graph::get_nei(size_t i, size_t j) {
        // Validate indices within graph dimensions
        if (i < 0 || i >= this->_nei.size() || j < 0 || j >= this->_nei.size()) {
            return 0; // Indicate invalid indices
        }

        // Access the value at the specified row (i) and column (j)
        return this->_nei[i][j];
    }

    bool Graph:: isSim(){

        for( size_t i=0; i<this->_nei.size(); i++)
        {
            for( size_t j=0; j<this->_nei.size(); j++)
            {
                if(this->_nei[i][j]!=this->_nei[j][i])
                    return false;
            }
        }
        return true;
    }
    
    

    
    
}