#pragma once

struct Position
{
    int x;
    int y;

    Position() = default;
    Position(int x_, int y_);

    bool operator==(const Position& other) const;
};