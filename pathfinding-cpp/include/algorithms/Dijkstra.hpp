#include <Base.hpp>

class Dijkstra : public PathFinder {

public:
	std::vector<Node*> findPath(Grid& grid, const Position& start, const Position& endPos) override;

};