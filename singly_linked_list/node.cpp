#include "node.hpp"

template <typename T>
Node<T>::Node(const Node<T> &other) :
    data(other.data),
    next(other.next)
{}

template <typename T>
Node<T>::Node(const T &data, Node *next) :
    data(data),
    next(next)
{}