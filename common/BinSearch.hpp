#pragma once
#include <vector>
#include <iostream>
#include <initializer_list>

template <typename T>
class BinSearch {
public:
    explicit BinSearch(std::initializer_list<T> values);
    template <typename IteratorT>
    explicit BinSearch(IteratorT begin, IteratorT end);
    int find(T&& val, int beg = 0, std::optional<int> end = std::nullopt);
    int find(T&& val, int beg, int end);
private:
    std::vector<T> _container;
};

template <typename T>
inline BinSearch<T>::BinSearch(std::initializer_list<T> values)
    : _container(values) {}

template <typename T>
inline int BinSearch<T>::find(T&& val, int beg, std::optional<int> end) {
    return find(std::forward<T>(val), beg, end.value_or(_container.size()));
}

template <typename T>
inline int BinSearch<T>::find(T&& val, int beg, int end) {
    while (beg < end) {
        int mid = beg + (end - beg) / 2;
        if (_container[mid] == val)
            return mid;
        if (_container[mid] < val)
            beg = mid + 1;
        else
            end = mid;
    }
    return -1;
}

template <typename T>
template <typename IteratorT>
inline BinSearch<T>::BinSearch(IteratorT begin, IteratorT end)
    : _container(begin, end) {}
