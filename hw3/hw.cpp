#include "BinSearch.hpp"
#include "Heap.hpp"
#include "hw.hpp"

std::vector<int> Solution::findClosestElements(std::vector<int>& arr, int k,
                                               int x) {
    struct DistVal
    {
        int dist;
        int val;
    };
    
    auto compFunc = [](const DistVal& v1, const DistVal& v2) {
        return v1.dist > v2.dist;
    };
    auto h = Heap<DistVal>(std::move(compFunc));
    for (int i{ 0 }; i < k; ++i)
        h.push({std::abs(arr[i] - x), arr[i]});
    for (int i{ k }; i < arr.size(); ++i) {
        auto newDist = std::abs(arr[i] - x);
        if (h.top().dist > newDist) {
            h.pop();
            h.push({newDist, arr[i]});
        }
    }
    std::vector<int> res;
    while (not h.empty()) {
        res.push_back(h.top().val);
        h.pop();
    }
    std::sort(res.begin(), res.end());
    return res;
}

ListNode* Solution::mergeKLists(std::vector<ListNode*>& lists) {
    auto compNodes = [](ListNode* n1, ListNode* n2) {
        return n1->val < n2->val;
    };
    Heap<ListNode*> h(std::move(compNodes));
    for (auto& list : lists) {
        if (list != nullptr)
            h.push(list);
    }
    if (h.empty())
        return nullptr;
    ListNode* head = h.top();
    h.pop();
    ListNode* curr = head;
    if (curr->next != nullptr)
        h.push(curr->next);
    while (not h.empty())
    {
        curr->next = h.top();
        h.pop();
        curr = curr->next;
        if (curr->next != nullptr)
            h.push(curr->next);
    }
    return head;       
}

std::vector<std::pair<int, size_t>> histogram(std::vector<int>& inpVec) {
    std::vector<std::pair<int, size_t>> res;
    size_t l{0}, r{inpVec.size()};
    while (l < r) {
        int target = inpVec[l];
        size_t initL = l;
        while (l < r) {
            size_t m = l + (r - l) / 2;
            if (inpVec[m] != target) {
                r = m;
                continue;
            }
            if (r == l + 1 or inpVec[m + 1] != target) {
                res.push_back({target, m + 1 - initL});
                l = m + 1;
                break;
            }
            l = m + 1;
        }
        r = inpVec.size();
    }
    return res;
}
