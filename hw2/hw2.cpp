#include <vector>
#include <utility>
#include <numeric>
#include <unordered_set>
#include <queue>
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

std::vector<int> Solution::intersection(std::vector<int>& nums1,
                                        std::vector<int>& nums2) {
    auto nums1Set = std::unordered_set<int>(nums1.begin(), nums1.end());
    std::unordered_set<int> resSet;
    for (int el : nums2)
        if (nums1Set.count(el)) resSet.insert(el);
    return std::vector<int>(resSet.begin(), resSet.end());
}

std::vector<int> Solution::distanceK(TreeNode* root, TreeNode* target, int k) {
    std::unordered_map<int, std::pair<TreeNode*, TreeNode*>> nodeMap;
    nodeMap[root->val] = {root, nullptr};
    std::vector<TreeNode*> currChild{root};
    while (not currChild.empty()) {
        std::vector<TreeNode*> nextChild;
        for(auto node : currChild) {
            if (node->left) {
                nextChild.push_back(node->left);
                nodeMap[node->left->val] = {node->left, node};
            }
            if (node->right) {
                nextChild.push_back(node->right);
                nodeMap[node->right->val] = {node->right, node};
            }
        }
        currChild = std::move(nextChild);
    }
    
    std::queue<int> bfsQ;
    std::unordered_set<int> visited;
    bfsQ.push(target->val);
    while (not bfsQ.empty())
    {
        if (k == 0) {
            std::vector<int> res;
            res.reserve(bfsQ.size());
            while (not bfsQ.empty()) {
                res.push_back(bfsQ.front());
                bfsQ.pop();
            }
            return res;
        }
        size_t N = bfsQ.size();
        for (int i{ 0 }; i < N; ++i) {
            auto node = nodeMap[bfsQ.front()];
            visited.insert(node.first->val);
            bfsQ.pop();
            if (node.second and not visited.count(node.second->val))
                bfsQ.push(node.second->val);
            if (node.first->left and not visited.count(node.first->left->val))
                bfsQ.push(node.first->left->val);
            if (node.first->right and not visited.count(node.first->right->val))
                bfsQ.push(node.first->right->val);
        }
        --k;
    }
    return std::vector<int>();
}
