#include <Position.hpp>


Position::Position(int x_, int y_)
    : x(x_), y(y_) {

}


bool Position::operator==(const Position& other) const
{
    return x == other.x && y == other.y;
}