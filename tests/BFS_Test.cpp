#include <core/Grid.hpp>
#include <core/Position.hpp>
#include <core/Node.hpp>
#include <algorithms/BFS.hpp>
#include <utils/Logger.hpp>
#include <utils/Timer.hpp>

#include <fstream>
#include <filesystem>
#include <memory>


typedef struct Data {
	Grid* ptr;
	Position start;
	Position end;

	Data(Grid* ptr, Position start, Position end) :ptr(ptr), start(start), end(end) {

	}
};


void testBFS(Data* ptr, bool output) {

	Position start(0, 0);
	Position end(0, 0);
	Grid* grid = nullptr;

	Logger log;

	if (ptr != nullptr) {
		grid = ptr->ptr;
		start = ptr->start;
		end = ptr->end;
	}
	else {
		grid = new Grid(10, 10);

		grid->getNode(1, 0).walkable = false;
		grid->getNode(2, 1).walkable = false;
		grid->getNode(4, 5).walkable = false;

		end.x = 9;
		end.y = 9;
	}



	BFS test;
	Timer time;

	auto path = test.findPath(*grid, start, end);

	time.stopTimer();

	std::cout << std::fixed << std::setprecision(16)
		<< "BFS took: " << time.getTime() << " seconds" << std::endl;

	if (!path.empty() && path.back()->pos == end && path.front()->pos == start && output) {
		log.INFO("Found path : ");

		for (auto spot : path) {
			log.INFO(("(" + std::to_string(spot->pos.x) + "," + std::to_string(spot->pos.y) + ")"));
		}

	}
	else if (path.empty()) {
		log.INFO("No possible route");
	}
}
