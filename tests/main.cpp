#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <random>
#include <ctime>

#include <core/Grid.hpp>
#include <core/Position.hpp>

struct Data {
    Grid* ptr;
    Position start;
    Position end;

    Data(Grid* ptr, Position start, Position end)
        : ptr(ptr), start(start), end(end) {
    }
};

Data* LoadFromVector(const std::vector<std::vector<char>>& data)
{
    if (data.empty())
        return nullptr;

    size_t width = data[0].size();

    for (const auto& row : data) {
        if (row.size() != width)
            return nullptr;
    }

    Grid* grid = new Grid(static_cast<int>(width), static_cast<int>(data.size()));

    Position start(-1, -1);
    Position end(-1, -1);

    for (size_t y = 0; y < data.size(); ++y) {
        for (size_t x = 0; x < width; ++x) {

            char cell = data[y][x];

            if (cell == '#') {
                grid->getNode(static_cast<int>(x), static_cast<int>(y)).walkable = false;
            }
            else if (cell == 'S') {
                start = Position(static_cast<int>(x), static_cast<int>(y));
            }
            else if (cell == 'E') {
                end = Position(static_cast<int>(x), static_cast<int>(y));
            }
        }
    }

    if (start.x == -1 || end.x == -1)
        return nullptr;

    return new Data(grid, start, end);
}

Data* LoadFromFile(const std::string& path)
{
    std::ifstream file(path);

    if (!file.is_open()) {
        return nullptr;
    }

    std::vector<std::vector<char>> data;
    std::string line;

    while (std::getline(file, line)) {

        if (!line.empty() && line.back() == '\r')
            line.pop_back();

        if (line.empty()) continue;

        data.emplace_back(line.begin(), line.end());
    }

    file.close();

    return LoadFromVector(data);
}

std::vector<std::vector<char>> generateRandomMap(int N, double obstacleChance = 0.2) {
    std::vector<std::vector<char>> map(N, std::vector<char>(N, '.'));

    std::mt19937 rng(static_cast<unsigned int>(time(nullptr)));
    std::uniform_real_distribution<> dist(0.0, 1.0);

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            if ((x == 0 && y == 0) || (x == N - 1 && y == N - 1)) continue; 
            if (dist(rng) < obstacleChance) map[y][x] = '#';
        }
    }

    map[0][0] = 'S';      
    map[N - 1][N - 1] = 'E';   

    return map;
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

void testDijkstra(Data* data, bool output);
void testBFS(Data* data, bool output);

int main()
{
    /*
    Data* data = LoadFromFile("map.txt");

    if (!data) {
        data = LoadFromVector(map);
    }

    if (!data) {
        return 1;
    }
    */
    auto data = LoadFromVector(generateRandomMap(2000));
    
    testBFS(data, false);
    testDijkstra(data, false);

    delete data->ptr;
    delete data;

    return 0;
} // ngl chat gpt  (after 1h of constant errors ) wrote me this random thing