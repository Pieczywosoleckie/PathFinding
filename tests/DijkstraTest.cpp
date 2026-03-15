#include <core/Grid.hpp>
#include <core/Position.hpp>
#include <core/Node.hpp>
#include <algorithms/Dijkstra.hpp>
#include <utils/Logger.hpp>
#include <utils/Timer.hpp>

#include <fstream>
#include <filesystem>

typedef struct Data {
	Grid* ptr;
	Position start;
	Position end;

	Data(Grid* ptr, Position start, Position end) :ptr(ptr), start(start), end(end) {

	}

};

Data* LoadFromVector(std::vector<std::vector<char>> data) {

	if (data.empty()) return nullptr;

	int lenght = data.at(0).size();

	for (auto y : data) {
		if (lenght != y.size()) {
			return nullptr;
		}
	}

	Grid* ptr = new Grid(data.size(), lenght);
	Position start(-1,-1);
	Position end(-1,-1);

	for (int y = 0; y < data.size(); ++y) {
		for (int x = 0; x < lenght; ++ x) {
			if (data.at(y).at(x) == '#') {
				ptr->getNode(x, y).walkable = false;
			}
			else if (data.at(y).at(x) == 'S') {
				start.x = x;
				start.y = y;
			}
			else if (data.at(y).at(x) == 'E') {
				end.x = x;
				end.y = y;
			}
		}
	}

	if (start.x == -1 || end.x == -1) {
		return nullptr;
	}

	return new Data(ptr, start, end);
}

void testDijkstra(Data* ptr) {

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



	Dijkstra test;
	Timer time;

	auto path = test.findPath(*grid, start, end);

	time.stopTimer();

	std::cout << std::fixed << std::setprecision(16)
		<< "Dijkstra took: " << time.getTime() << " seconds" << std::endl;

	if (!path.empty() && path.back()->pos == end && path.front()->pos == start) {
		log.INFO("Found path : ");

		for (auto spot : path) {
			log.INFO(("(" + std::to_string(spot->pos.x) + "," + std::to_string(spot->pos.y) + ")"));
		}

	}

}

int main() {

	
	std::vector<std::vector<char>> map = {
		{ 'S', '.', '.', '.', '#', '.', '.' },
		{ '.', '#', '.', '.', '#', '.', '.' },
		{ '.', '#', '.', '#', '#', '.', '.' },
		{ '.', '#', '.', '.', '.', '.', '.' },
		{ '.', '.', '#', '#', '#', '.', '.' },
		{ '.', '.', '.', '.', '#', '.', '.' },
		{ '.', '.', '.', '.', '#', '.', 'E' }
	};

	testDijkstra(LoadFromVector(map));

	std::cout << "Test completed! " << std::endl;
	return 0;
}