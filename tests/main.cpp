#include <vector>
#include <iostream>
#include <core/Grid.hpp>
#include <core/Position.hpp>


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
	Position start(-1, -1);
	Position end(-1, -1);

	for (int y = 0; y < data.size(); ++y) {
		for (int x = 0; x < lenght; ++x) {
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

std::vector<std::vector<char>> map = {
		{ 'S', '.', '.', '.', '#', '.', '.' },
		{ '.', '#', '.', '.', '#', '.', '.' },
		{ '.', '#', '.', '#', '#', '.', '.' },
		{ '.', '#', '.', '.', '.', '.', '.' },
		{ '.', '.', '#', '#', '#', '.', '.' },
		{ '.', '.', '.', '.', '#', '.', '.' },
		{ '.', '.', '.', '.', '#', '.', 'E' }
};

void testDijkstra(Data* ptr);
void testBFS(Data* ptr);

int main() {

	testDijkstra(LoadFromVector(map));
	testBFS(LoadFromVector(map));

}