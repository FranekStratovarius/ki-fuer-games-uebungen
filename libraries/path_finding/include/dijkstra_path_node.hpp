#ifndef DIJKSTRA_PATH_NODE_HPP
#define DIJKSTRA_PATH_NODE_HPP

#include "graph_node.hpp"

struct DijkstraPathNode {
	DijkstraPathNode* prevNode = nullptr;
	GraphNode *node;
	float accumulated_costs = 0;
};

#endif // DIJKSTRA_PATH_NODE_HPP