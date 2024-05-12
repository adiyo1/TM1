#ifndef GRAPH_HPP
#define GRAPH_HPP


#include <iostream>
#include <vector>

using namespace std;

namespace ariel {


    class Graph {

        vector<vector<int>> _nei;
        bool _isSim;
        public:
            
            Graph();
            vector<vector<int>>& getNei();
            void loadGraph(vector<vector<int>> graph);
            void printGraph();
            size_t get_size();
            int get_nei(size_t i, size_t j);
            bool isSim();

    };
}

#endif