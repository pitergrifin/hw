#pragma once
#include <vector>
#include <new> 

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x);
    ListNode* mergeKLists(std::vector<ListNode*>& lists);
};

std::vector<std::pair<int, size_t>> histogram(std::vector<int>& inpVec);

struct 
#ifdef OPTIMIZED
alignas(std::hardware_destructive_interference_size)
#endif
Foo {
    int a{0};
    #ifdef OPTIMIZED
    char padding[std::hardware_destructive_interference_size - sizeof(int)];
    #endif
    int b{0};
};