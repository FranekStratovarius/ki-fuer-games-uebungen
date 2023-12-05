#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "graph_node.hpp"

class Graph {
	public:
		Graph();
		Graph(std::vector<GraphNode*> nodes);
		void addNode(GraphNode *node);
		void addEdge(GraphNode *start, GraphNode *end);
		std::vector<GraphNode*> getGraph();
	private:
		std::vector<GraphNode*> nodes;
};

#endif // GRAPH_HPP