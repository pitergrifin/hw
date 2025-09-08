#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include "hw1.hpp"

int deleteSpaces(std::string& line) {
    int toWrite{ 0 };
    for (auto ch : line) {
        if (ch != ' ')
            line[toWrite++] = ch;
    }
    return toWrite;
}

void subsSpaces(std::string& line) {
    // Count number of spaces
    int nSpace{ 0 };
    for (auto ch : line)
        if (ch == ' ') ++nSpace;
    line.resize(line.size() + nSpace * 2);
    size_t toWrite{ line.size() - 1 };
    for (int i = static_cast<int>(line.size() - 1 - nSpace * 2); i >= 0; --i) {
        if(line[i] != ' ')
            line[toWrite--] = line[i];
        else {
            line[toWrite--] = '0';
            line[toWrite--] = '2';
            line[toWrite--] = '%';
        }
    }
}

std::vector<int> SolutionRSV::rightSideView(TreeNode* root) {
    std::vector<int> res;
    if (not root) return res;
    std::vector<TreeNode*> currChild{root};
    while(not currChild.empty()) {
        res.push_back(currChild.back()->val);
        std::vector<TreeNode*> nextChild;
        for (auto node : currChild) {
            if (node->left) nextChild.push_back(node->left);
            if (node->right) nextChild.push_back(node->right);
        }
        currChild = std::move(nextChild);
    }
    return res;
}

std::vector<std::vector<int>> SolutionLOT::levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> res;
    if (not root) return res;
    std::vector<TreeNode*> currChild{root};
    while(not currChild.empty()) {
        std::vector<int> currChildVal{};
        std::vector<TreeNode*> nextChild;
        for (auto node : currChild) {
            currChildVal.push_back(node->val);
            if (node->left) nextChild.push_back(node->left);
            if (node->right) nextChild.push_back(node->right);
        }
        res.push_back(currChildVal);
        currChild = std::move(nextChild);
    }
    return res;
}

std::vector<int> SolutionTwoSum::twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map;
    for (int i{0}; i < nums.size(); ++i) {
        if (map.count(target - nums[i]))
            return {map[target - nums[i]], i};
        map[nums[i]] = i;
    }
    return {};
}

std::atomic<int> curr_max;
void feed(int candidate) {
    for (int cand_max{curr_max.load()}; candidate > cand_max; cand_max = curr_max.load()) {
        curr_max.compare_exchange_weak(cand_max, candidate);
    }
}