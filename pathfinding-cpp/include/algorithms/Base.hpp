#pragma once 
#include <vector>
#include <core/Grid.hpp>
#include <utils/Logger.hpp>
#include <utils/Timer.hpp>

class PathFinder {
public:

	virtual std::vector<Node*> findPath(Grid& grid, const Position& startPos, const Position& endPos) = 0;

	virtual ~PathFinder() = default;

};