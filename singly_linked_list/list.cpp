#include "list.hpp"

#include <stdexcept>
#include <sstream>

template <typename T>
List<T>::List(size_t size, const T &value) :
    _size(size)
{
    _head = new Node<T>(value, nullptr);

    Node<T> *current = _head;

    for (size_t i = 0; i < size - 1; ++i) {
        current->next = new Node<T>(value, nullptr);
        current = current->next;
    }
}

template <typename T>
List<T>::List(const List<T> &other) :
    _size(other.size())
{
    _head = new Node<T>(other.head()->data);

    Node<T> *current = _head;
    Node<T> *current_other = other.head();

    while (current_other != nullptr) {
        current = new Node<T>(current_other->data);
    }
}

template <typename T>
List<T>::~List()
{
    clear();
}

template <typename T>
List<T> &List<T>::operator=(const List<T> &other)
{
    clear();

    this->_head = other.head();
    this->_size = other.size();
}

template <typename T>
Node<T> *List<T>::head() const
{
    return _head;
}

template <typename T>
bool List<T>::empty() const
{
    return _size == 0;
}

template <typename T>
size_t List<T>::size() const
{
    return _size;
}

template <typename T>
void List<T>::clear()
{
    if (_head == nullptr)
        return;

    Node<T> *tmp;

    while (_head != nullptr) {
        tmp = _head->next;

        delete _head;
        
        _head = tmp;
    }

    _size = 0;
}

template<typename T>
void List<T>::erase(size_t from, size_t to)
{

}

template<typename T>
void List<T>::insert(size_t index, const List &other)
{
    if (index == 0);

    Node<T> *insert_after = node_by_index(index - 1);


}

template<typename T>
T List<T>::at(size_t index) const
{
    size_t i = 0;

    Node<T> *current = _head;

    while (i < index && current != nullptr) {
        current = current->next;
        ++i;
    }

    if (i < index) {
        std::stringstream ss;

        ss << "at() index " << index 
           << " greater then list last index, which is " 
           << _size - 1;

        throw std::out_of_range(ss.str());
    }

    return current->data;
}

#include <iostream>

template <typename T>
T &List<T>::operator[](size_t index)
{
    size_t i = 0;

    Node<T> *current = _head;

    while (i < index && current != nullptr) {
        current = current->next;
        ++i;
    }

    if (i < index || i >= _size) {
        std::stringstream ss;

        ss << "[] index " << index 
           << " greater then list last index, which is " 
           << _size - 1;

        throw std::out_of_range(ss.str());
    }

    return current->data;
}

template <typename T>
void List<T>::reverse()
{
    if (_head == nullptr)
        return;

    Node<T> *prev = nullptr;
    Node<T> *current = _head;
    Node<T> *next = _head->next;

    while (next != nullptr) {
        next = current->next;

        current->next = prev;

        _head = current;

        prev = current;

        current = next;
    }
}

template <typename T>
void List<T>::sort()
{
    
}

template <typename T>
void List<T>::push_back(T value)
{
    if (_head == nullptr) {
        _head = new Node<T>(value);
        return;
    }

    Node<T> *last = node_by_index(_size - 1);
    
    last->next = new Node<T>(value);
}

template <typename T>
void List<T>::push_front(T value)
{
    Node<T> *new_head = new Node<T>(value, _head);
    
    _head = new_head;
}

template <typename T>
void List<T>::fill(T value)
{
    Node<T> *current = _head;

    while(current != nullptr) {
        current->data = value;

        current = current->next;
    }
}

template <typename T>
Node<T> *List<T>::node_by_index(size_t index)
{
    size_t i = 0;

    Node<T> *current = _head;

    while (i < index && current != nullptr) {
        current = current->next;
        ++i;
    }

    if (i < index) {
        std::stringstream ss;

        ss << "Index " << index 
           << " greater then list last index, which is " 
           << _size - 1;

        throw std::out_of_range(ss.str());
    }
    
    return current;
}