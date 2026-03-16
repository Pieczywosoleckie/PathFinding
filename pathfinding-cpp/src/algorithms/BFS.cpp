#include <algorithms/BFS.hpp>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

#include <memory>

std::vector<Node*> BFS::findPath(Grid& grid, const Position& start, const Position& end) {
	if (start.x == end.x && start.y == end.y) { return {}; }

	std::vector<Position> dirs = { {1,0}/*right*/ ,{0,1}/*up*/ , {-1,0} /*left*/ , {0,-1} /*down*/ };
	std::queue<Node*> q;

	Node* startNode = &grid.getNode(start.x, start.y);
	startNode->visited = true;
	q.push(startNode);

	while (!q.empty()) {

		Node* current = q.front();
		q.pop();

		if (current->pos == end) {
			std::vector<Node*> path;
			Node* node = current;
			while (node) {
				path.emplace_back(node);
				node = node->parent;
			}
			std::reverse(path.begin(), path.end());
			return path;
		}

		for (auto& d : dirs) {
			int nx = current->pos.x + d.x;
			int ny = current->pos.y + d.y;

			if (!grid.isInside(nx, ny)) continue;

			Node* next = &grid.getNode(nx,ny);

			if (!next->visited && next->walkable) {
				next->visited = true;
				next->parent = current;

				q.push(next);
			}
		}
	}
	
	

	return {};
}