#ifndef GRAPH_HPP
#define GRAPH_HPP


#include <iostream>
#include <vector>

using namespace std;

namespace ariel {


    class Graph {

        vector<vector<size_t>> _nei;
        bool _isSim;
        public:
            
            Graph();
            vector<vector<size_t>>& getNei();
            void loadGraph(vector<vector<size_t>> graph);
            void printGraph();
            size_t get_size();
            int get_nei(size_t i, size_t j);
            bool isSim();

    };
}

#endif