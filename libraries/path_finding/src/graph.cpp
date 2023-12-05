#include "graph.hpp"
#include "graph_node.hpp"
#include "raymath.h"

Graph::Graph() {}

Graph::Graph(std::vector<GraphNode*> nodes) {
	this->nodes = nodes;
}

void Graph::addNode(GraphNode *node) {
	nodes.push_back(node);
}

void Graph::addEdge(GraphNode *start, GraphNode *end) {
	float distance = Vector2Length(
		Vector2Subtract(
			start->Position,
			end->Position
		)
	);
	start->edges.push_back(GraphEdge{
		.costs = distance,
		.start = start,
		.end = end
	});
}

std::vector<GraphNode*> Graph::getGraph() {
	return this->nodes;
}