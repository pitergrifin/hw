#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() {
        delete left; 
        delete right;
    }
};
TreeNode* buildTree(const std::vector<std::optional<int>>& vals);

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