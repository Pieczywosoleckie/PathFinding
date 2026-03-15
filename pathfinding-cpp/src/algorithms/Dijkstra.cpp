#include <algorithms/Dijkstra.hpp>

#include <core/Grid.hpp>
#include <core/Position.hpp>
#include <core/Node.hpp>

#include <algorithm>


std::vector<Node*> Dijkstra::findPath(Grid& grid, const Position& start, const Position& end) {
	Node& startNode = grid.getNode(start.x, start.y);
	Node& endNode = grid.getNode(end.x, end.y);

	for (int y = 0; y < grid.getHeight(); ++y) {
		for (int x = 0; x < grid.getWidth(); ++x) {
			Node& pole = grid.getNode(x, y);
			pole.gCost = std::numeric_limits<float>::infinity();
			pole.parent = nullptr;

		}
	}

	startNode.gCost = 0;

	std::vector<Node*> list;
	list.push_back(&startNode);

	std::vector<Position> dirs = { {0,1}, {1,0}, {0,-1}, {-1,0} };

	while (!list.empty()) {
		auto LowestCost = std::min_element(list.begin(), list.end(), 
			[](Node* node1, Node* node2) 
			{
			return node1->gCost < node2->gCost;
		});

		Node* now = *LowestCost;

		list.erase(LowestCost);

		if (now->pos == end) {
			std::vector<Node*> res;
			Node* node = now;

			while (node) {
				res.push_back(node);
				node = node->parent;
			}
			std::reverse(res.begin(), res.end());
			return res;
		}

		for (const auto& dir : dirs) {
			
			int node_x = now->pos.x + dir.x;
			int node_y = now->pos.y + dir.y;

			if (!grid.isInside(node_x, node_y)) continue;

			Node& next = grid.getNode(node_x, node_y);

			if (!next.walkable) continue;

			float tmp_ = now->gCost + 1.0;
			if (tmp_ < next.gCost) {
				next.gCost = tmp_;
				next.parent = now;

				if (std::find(list.begin(), list.end(), &next) == list.end()) {
					list.push_back(&next);
				}

			}

		}

	}

	return {};
}