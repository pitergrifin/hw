#include <vector>
#include <optional>
#include "Tree.hpp"

class SolutionRSV {
public:
    std::vector<int> rightSideView(TreeNode* root);
};

class SolutionLOT {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root);
};
int deleteSpaces(std::string& input);
void subsSpaces(std::string& input);

class SolutionTwoSum {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target);
};