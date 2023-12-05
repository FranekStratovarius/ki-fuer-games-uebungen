#ifndef GRAPH_NODE_HPP
#define GRAPH_NODE_HPP

#include "raymath.h"
#include <vector>

struct GraphNode;

struct GraphEdge {
	float costs;
	GraphNode *start;
	GraphNode *end;
};

struct GraphNode {
	Vector2 Position;
	std::vector<GraphEdge> edges = {};
};

#endif // GRAPH_NODE_HPP