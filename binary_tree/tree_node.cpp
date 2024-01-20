#include "tree_node.hpp"

// template<class T>
TreeNode::TreeNode()
{}

TreeNode::TreeNode(int value) :
    _value(value)
{}

TreeNode::TreeNode(const TreeNode &other) :
    _value(other.value()),
    _left(other.left()),
    _right(other.right())
{}

int TreeNode::value() const
{
    return _value;
}

// template<class T>
TreeNode *TreeNode::left() const
{
    return _left;
}

// template<class T>
TreeNode *TreeNode::right() const
{
    return _right;
}