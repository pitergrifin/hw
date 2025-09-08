#include <catch2/catch_all.hpp>
#include <string>
#include <vector>
#include <memory>
#include "hw1.hpp"

struct TestCaseData {
    std::string input;
    std::string expectedRemove;
    std::string expectedReplace;
};

static const std::vector<TestCaseData> testCases = {
    {"hello world",    "helloworld",   "hello%20world"},
    {"   leading",     "leading",      "%20%20%20leading"},
    {"trailing   ",    "trailing",     "trailing%20%20%20"},
    {"in  between",    "inbetween",    "in%20%20between"},
    {"noSpaces",       "noSpaces",     "noSpaces"},
    {"   ",            "",             "%20%20%20"},
    {"",               "",             ""}
};

TEST_CASE("deleteSpaces removes all spaces", "[deleteSpaces]") {
    for (auto tc : testCases) {
        int numCh = deleteSpaces(tc.input);
        REQUIRE(tc.input.substr(0, numCh) == tc.expectedRemove);
    }
}

TEST_CASE("subsSpaces replaces spaces with %20", "[subsSpaces]") {
    for (auto tc : testCases) {
        subsSpaces(tc.input);
        REQUIRE(tc.input == tc.expectedReplace);
    }
}

struct TestBinaryTree {
   std::vector<std::optional<int>> inp;
   std::vector<int> rightSideView;
   std::vector<std::vector<int>> levelOrder;
};

static const std::vector<TestBinaryTree> testRightViewData = {
    {{1,2,3,std::nullopt,5,std::nullopt,4}, {1,3,4}, {{1},{2,3},{5,4}}},
    {{1,2,3,4,std::nullopt,std::nullopt,std::nullopt,5}, {1,3,4,5}, {{1},{2,3},{4},{5}}},
    {{1,std::nullopt,3}, {1,3}, {{1},{3}}},
    {{3,9,20,std::nullopt,std::nullopt,15,7}, {3, 20, 7}, {{3},{9,20},{15,7}}},
    {{1}, {1}, {{1}}},
    {{},{},{}}
};

TEST_CASE("BT right side view", "[rightSideView]") {
    SolutionRSV sol;
    for (auto tc : testRightViewData) {
        std::unique_ptr<TreeNode> tree(buildTree(tc.inp));
        auto res = sol.rightSideView(tree.get());
        REQUIRE(res == tc.rightSideView);
    }
}

TEST_CASE("Level Order Traversal", "[levelOrder]") {
    SolutionLOT sol;
    for (auto tc : testRightViewData) {
        std::unique_ptr<TreeNode> tree(buildTree(tc.inp));
        auto res = sol.levelOrder(tree.get());
        REQUIRE(res == tc.levelOrder);
    }
}

TEST_CASE("Two Sum", "[twoSum]") {
    SolutionTwoSum sol;
    std::vector<int> inp, res;
    inp = {2, 7, 11, 15};
    res = {0, 1};
    REQUIRE(sol.twoSum(inp, 9) == res);
    inp = {3, 2, 4};
    res = {1, 2};
    REQUIRE(sol.twoSum(inp, 6) == res);
    inp = {3, 3};
    res = {0, 1};
    REQUIRE(sol.twoSum(inp, 6) == res);
}