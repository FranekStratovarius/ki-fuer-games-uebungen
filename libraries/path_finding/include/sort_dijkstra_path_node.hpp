#ifndef SORT_DIJKSTRA_PATH_NODE_HPP
#define SORT_DIJKSTRA_PATH_NODE_HPP

#include "dijkstra_path_node.hpp"

class SortDijkstraPathNode {
	public:
		bool operator()(const DijkstraPathNode *t1, const DijkstraPathNode *t2) const {
			return t1->accumulated_costs < t2->accumulated_costs;
		}
};

#endif // SORT_DIJKSTRA_PATH_NODE_HPP