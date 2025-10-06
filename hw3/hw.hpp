#pragma once
#include <vector>

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