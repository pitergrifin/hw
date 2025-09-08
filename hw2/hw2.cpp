#include <vector>
#include <utility>
#include <numeric>
#include <iostream>
#include "hw2.hpp"

int sumOfNodes(TreeNode* head) { 
    int dist{0};
    for (auto currNode = head; currNode->left != nullptr; currNode = currNode->left) ++dist;
    std::vector<std::pair<TreeNode*, int>> currChild{{head, dist}};
    int level{ 0 }, sum{ 0 };
    bool foundMin{false};
    while (not currChild.empty())
    {
        if (level % 2 == 0) {
            sum = std::accumulate(currChild.begin(), currChild.end(), sum, [](int currSum, const auto& currNode) {
                if (currNode.second % 3 == 0)
                    return currSum + currNode.first->val;
                return currSum;
            });
        }

        decltype(currChild) nextChild;
        if (currChild.front().first->left == nullptr)
            foundMin = true;
        for (auto [node, length] : currChild) {
            if (node->left)
                nextChild.push_back({node->left, length+1});
            if (node->right)
                nextChild.push_back({node->right, length+1});
        }
        if (not foundMin and not nextChild.empty())
            nextChild.front().second -= 2;
        currChild = std::move(nextChild);
        ++level;
    }
    
    return sum; 
}