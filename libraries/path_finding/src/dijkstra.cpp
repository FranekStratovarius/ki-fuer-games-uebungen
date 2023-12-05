#include "dijkstra.hpp"
#include "dijkstra_path_node.hpp"
#include "graph_node.hpp"
#include "sort_dijkstra_path_node.hpp"
#include <algorithm>
#include <set>

bool isClosed(
	std::multiset<DijkstraPathNode *, SortDijkstraPathNode> *closedList,
	GraphNode *node
) {
	for (auto it = closedList->begin(); it != closedList->end(); it++) {
		if ((*it)->node == node) {
			return true;
		}
	}
	return false;
}

DijkstraPathNode *isOpen(
	std::multiset<DijkstraPathNode *, SortDijkstraPathNode> *openList,
	GraphNode *node
) {
	for (auto it = openList->begin(); it != openList->end(); it++) {
		if ((*it)->node == node) {
			return *it;
		}
	}
	return nullptr;
}

void removeElement(
	std::multiset<DijkstraPathNode *, SortDijkstraPathNode> *list,
	DijkstraPathNode *node
) {
	for (auto it = list->begin(); it != list->end(); it++) {
		if ((*it) == node) {
			list->erase(it);
			return;
		}
	}
}

bool analyzeNeighbors(
	std::multiset<DijkstraPathNode *, SortDijkstraPathNode> *openList,
	std::multiset<DijkstraPathNode *, SortDijkstraPathNode> *closedList,
	DijkstraPathNode **currentNode,
	GraphNode *stop
) {
	// get first element
	(*currentNode) = *(openList->begin());
	if ( (*currentNode)->node == stop) {
		return false;
	}
	// remove first element
	removeElement(openList, *currentNode);
	// openList->erase((*currentNode));

	for (GraphEdge edge : (*currentNode)->node->edges) {
		// skip visited nodes
		if (isClosed(closedList, edge.end)) {
			continue;
		}
		// calculate new cost
		float cost = (*currentNode)->accumulated_costs + edge.costs;
		// check if node is already in openList
		DijkstraPathNode *openNode = isOpen(openList, edge.end);
		// don't add node if node is already in openList
		if (openNode != nullptr) {
			if (cost > openNode->accumulated_costs) {
				openNode->accumulated_costs = cost;
			}
			continue;
		}
		// add to openList
		openList->insert(new DijkstraPathNode{
			.prevNode = (*currentNode),
			.node = edge.end,
			.accumulated_costs = cost
		});
	}
	// put last open node into closedList
	closedList->insert(*currentNode);
	return openList->size() != 0;
}

std::vector<GraphNode*> computeDijkstra(GraphNode *start, GraphNode *stop) {
	std::multiset<DijkstraPathNode *, SortDijkstraPathNode> *openList = new std::multiset<DijkstraPathNode *, SortDijkstraPathNode>;
	std::multiset<DijkstraPathNode *, SortDijkstraPathNode> *closedList = new std::multiset<DijkstraPathNode *, SortDijkstraPathNode>;
	openList->insert(new DijkstraPathNode{ .node = start});
	DijkstraPathNode *currentNode = new DijkstraPathNode{ .node = start};

	while (analyzeNeighbors(openList, closedList, &currentNode, stop));

	// convert dijkstra path to array of graph nodes
	std::vector<GraphNode*> path;
	while (currentNode != nullptr) {
		path.push_back(currentNode->node);
		currentNode = currentNode->prevNode;
	}
	// reverse order in vector because we started traversing the target path from the end
	std::reverse(path.begin(), path.end());
	delete currentNode;
	return path;
}
