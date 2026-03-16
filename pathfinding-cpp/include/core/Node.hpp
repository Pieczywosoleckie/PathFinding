#pragma once
#include <core/Position.hpp>

struct Node
{
    Position pos;

    Node* parent = nullptr;

    bool walkable = true;
    bool visited = false;

    float gCost = 0.0f;
    float hCost = 0.0f;

    Node(int x, int y, bool walkable_ = true);
    Node(Position pos, bool walkable);

    float fCost() const;
};