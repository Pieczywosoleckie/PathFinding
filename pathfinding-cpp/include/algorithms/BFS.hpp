#pragma once

#include <algorithms/Base.hpp>
#include <vector>

class BFS {

public:
	std::vector<BFSNode*> findPath(Grid& grid, const Position& start, const Position& end);

};