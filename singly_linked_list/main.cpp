#include "list.hpp"
#include "profile.h"

#include <iostream>
#include <string>
#include <list>

struct Square
{
    Square(size_t size) :
        size(size)
    {}

    size_t size = 0;
};

std::ostream &operator<<(std::ostream &os, const Square &square)
{
    const size_t size = square.size;

    if (size < 1)
        return os;

    if (size == 1)
        return os << "*";

    os << '\n';

    for (size_t i = 0; i < size; ++i)
        os << "* ";

    os << '\n';

    for (size_t i = 0; i < size - 2; ++i) {
        os << "* ";

        for (size_t j = 0; j < size - 2; ++j)
            os << "  ";

        os << "*";
        os << '\n';
    }


    for (size_t i = 0; i < size; ++i)
        os << "* ";

    return os << '\n';
} 

template <typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &list) 
{
    bool first = true;

    os << "{ ";

    auto head = list.head();
    while (head != nullptr) {
        if (!first)
            os << ", ";

        first = false;

        os << head->data;

        head = head->next;
    }

    return os << " }";
}

void createMyList(size_t size)
{
    LOG_DURATION("my list");

    List<int> list(size, 0);

    list.clear();
}

void createStdList(size_t size)
{
    LOG_DURATION("std list");

    std::list<int> list(size, 0);

    list.clear();
}

int main(int argc, char *argv[])
{
    // List<std::string> list(10, "ss");

    // size_t size = 10000000;

    // createMyList(size);
    // createStdList(size);

    // List<int> list(size, 0);

    // int tmp;
    // std::cin >> tmp;

    // std::list<int> list(size, 0);

    // std::cin >> tmp;

    // list.clear();

    // std::cin >> tmp;

    // std::cout << list.size() << '\n';
    // std::cout << list.head() << '\n';

    // list.clear();

    // std::cout << list.size() << '\n';
    // std::cout << list.head() << '\n';

    // std::cout << list << '\n';

    size_t size = 10;

    List<int> list(size, 0);

    for (size_t i = 0; i < size; ++i) {
        list[i] = i;
    }

    std::cout << list << '\n';

    list.reverse();

    std::cout << list << '\n';

    list.push_back(-1);

    std::cout << list << '\n';

    list.push_front(10);

    std::cout << list << '\n';

    list.fill(888);

    std::cout << list << '\n';

    List<int> list2;

    std::cout << "list 2 " << list2 << '\n';

    list2.push_back(1);

    std::cout << "list 2 " << list2 << '\n';

    List<int> list3;

    std::cout << "list 3 " << list3 << '\n';

    list3.push_front(-1);

    std::cout << "list 3 " << list3 << '\n';

    return 0;
}