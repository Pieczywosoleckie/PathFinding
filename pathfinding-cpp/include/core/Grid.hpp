#pragma once
#include <vector>
#include <core/Node.hpp>

class Grid
{
private:
    int width;
    int height;

    std::vector<std::vector<Node>> nodes;

public:
    Grid(int w, int h);

    Node& getNode(int x, int y);

    bool isInside(int x, int y) const;

    int getWidth() const;
    int getHeight() const;

};