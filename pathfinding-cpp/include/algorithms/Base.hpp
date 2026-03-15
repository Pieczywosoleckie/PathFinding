#pragma once 
#include <vector>
#include <Grid.hpp>
#include <Logger.hpp>
#include <Timer.hpp>

class PathFinder {
public:

	virtual std::vector<Node*> findPath(Grid& grid, const Position& startPos, const Position& endPos) = 0;

	virtual ~PathFinder() = default;

};