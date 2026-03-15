#pragma once
#include <core/Position.hpp>

struct Node
{
    Position pos;

    bool walkable = true;

    float gCost = 0.0f;
    float hCost = 0.0f;

    Node* parent = nullptr;

    Node(int x, int y, bool walkable_ = true);

    float fCost() const;
};