#include <algorithms/BFS.hpp>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

struct BFSNode {
	Position pos;
	BFSNode* parent = nullptr;
	bool visited = false;
	bool walkable = true;

	BFSNode(Position pos, bool walkable) {
		this->pos = pos;
		this->walkable = walkable;
	}
};

std::vector<BFSNode*> BFS::findPath(Grid& grid, const Position& start, const Position& end) {
	if (start.x == end.x && start.y == end.y) { return {}; }

	Node& startNode = grid.getNode(start.x, start.y);
	Node& endNode = grid.getNode(end.x, end.y);

	std::vector<Position> dirs = { {1,0}/*right*/ ,{0,1}/*up*/ , {-1,0} /*left*/ , {0,-1} /*down*/ };

	std::vector<std::vector<BFSNode>> linkedlist;

	for (int y = 0; y < grid.getHeight(); y++) {
		std::vector<BFSNode> tmp_;
		for (int x = 0; x < grid.getWidth(); x++) {
			if (grid.isInside(x, y)) {
				BFSNode tmpNode_(Position(x, y), grid.getNode(x,y).walkable ? true : false);
				tmp_.push_back(tmpNode_);
			}
		}
		linkedlist.push_back(tmp_);
		tmp_.clear();
	}

	std::queue<BFSNode*> q;

	auto& startPos = linkedlist.at(start.y).at(start.x);
	startPos.visited = true;
	q.push(&startPos);

	while (!q.empty()) {

		BFSNode* current = q.front();
		q.pop();

		for (auto& d : dirs) {
			int nx = current->pos.x + d.x;
			int ny = current->pos.y + d.y;

			if (!grid.isInside(nx, ny)) continue;

			BFSNode& next = linkedlist[ny][nx];

			if (!next.visited && next.walkable) {
				next.visited = true;
				next.parent = current;

				if (nx == end.x && ny == end.y) {
					BFSNode* node = &next;

					std::vector<BFSNode*> path;

					while (node != nullptr) {
						path.emplace_back(&grid.getNode(node->pos.x , node->pos.y));
						node = node->parent;
					}

					std::reverse(path.begin(), path.end());
					return path;
				}

				q.push(&next);
			}
		}
	}
	
	

	return {};
}