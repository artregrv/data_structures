#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node
{
public:
    Node() = default;
    Node(const Node &other);
    Node(const T &data, Node *next = nullptr);

    T data;
    Node *next { nullptr };
};

#include "node.cpp"

#endif // NODE_HPP