#include <Grid.hpp>


Grid::Grid(int w, int h)
    : width(w), height(h) {
    for (int y = 0; y < height; y++)
    {
        std::vector<Node> row;

        for (int x = 0; x < width; x++)
        {
            row.emplace_back(x, y, true);
        }

        nodes.push_back(row);
    }
}

Node& Grid::getNode(int x, int y) {
    return nodes[y][x];
}


bool Grid::isInside(int x, int y) const {
    return x >= 0 && y >= 0 && x < width && y < height;
}


int Grid::getWidth() const { 
    return width; 
}

int Grid::getHeight() const {
    return height; 
}