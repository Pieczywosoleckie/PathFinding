#include <Core/Node.hpp>



Node::Node(int x, int y, bool walkable_)
    : pos(x, y), walkable(walkable_){

}

Node::Node(Position pos, bool walkable) {
    this->pos = pos;
    this->walkable = walkable;
}

float Node::fCost() const
{
    return gCost + hCost;
}