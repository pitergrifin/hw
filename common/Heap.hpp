#pragma once

#include <vector>

template<typename T>
class Heap {
    using Compare = std::function<bool(const T&, const T&)>;
public:
    Heap()
        : _comp(std::greater{}) {}
    explicit Heap(Compare comp);
    void push(const T& val);
    T top();
    void pop();
    bool empty();
private:
    void heapifyDown(int i) {
        int currChoise = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if (left < _tree.size() and _comp(_tree[left], _tree[currChoise]))
            currChoise = left;
        if (right < _tree.size() and _comp(_tree[right], _tree[currChoise]))
            currChoise = right;
        if (currChoise == i)
            return;
        std::swap(_tree[currChoise], _tree[i]);
        heapifyDown(currChoise);
    }
    void heapifyUp(int i) {
        if (i <= 0) return;
        int parent = (i-1)/2;
        if (_comp(_tree[i], _tree[parent])) {
            std::swap(_tree[i], _tree[parent]);
            heapifyUp(parent);
        }
    }
private:
    // 0 - root, for i-th Node we have 2*i+1 and 2*i+2 - children
    // So for Node j we have (j-1)/2 - parent
    std::vector<T> _tree{};
    Compare _comp{};
};

template <typename T>
inline Heap<T>::Heap(Compare comp) 
   : _comp(std::move(comp)) {}

template <typename T>
inline void Heap<T>::push(const T& val) {
    _tree.push_back(val);
    heapifyUp(_tree.size() - 1);
}

template <typename T>
inline T Heap<T>::top() {
    return _tree.front();
}

template <typename T>
inline void Heap<T>::pop() {
    if (_tree.empty()) return;
    _tree[0] = _tree.back();
    _tree.pop_back();
    heapifyDown(0);
}

template <typename T>
inline bool Heap<T>::empty() {
    return _tree.empty();
}