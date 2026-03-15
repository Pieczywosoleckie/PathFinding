#include <Core/Node.hpp>



Node::Node(int x, int y, bool walkable_)
    : pos(x, y), walkable(walkable_){

}

float Node::fCost() const
{
    return gCost + hCost;
}