#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "graph_node.hpp"
#include "dijkstra_path_node.hpp"

std::vector<GraphNode*> computeDijkstra(GraphNode *start, GraphNode *stop);

#endif // DIJKSTRA_HPP