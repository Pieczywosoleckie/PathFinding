#pragma once

#include <algorithms/Base.hpp>
#include <vector>

class Dijkstra : public PathFinder {

public:
	std::vector<Node*> findPath(Grid& grid, const Position& start, const Position& end) override;

};