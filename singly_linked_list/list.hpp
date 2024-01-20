#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"

#include <stddef.h>
#include <initializer_list>

template <typename T>
class List
{
public:
    List() = default;
    List(size_t size, const T &value);
    List(const List &other);
    List(const List &&other); // ???
    List(std::initializer_list<T> values);
    ~List();

    List<T> &operator=(const List<T> &other);

    Node<T> *head() const;
    bool empty() const;

    size_t size() const;
    void clear();
    void erase(size_t from, size_t to);
    void insert(size_t index, const List &other);
    T at(size_t index) const;
    T &operator[](size_t index);
    void reverse();
    void sort();
    void push_back(T value);
    void push_front(T value);
    void fill(T value);

private:
    Node<T> *node_by_index(size_t index);

private:
    Node<T> *_head { nullptr };
    size_t _size { 0 };
};

// for correct linking
#include "list.cpp"

#endif // LIST_HPP