#include <catch2/catch_all.hpp>
#include <string>
#include <vector>
#include <memory>
#include <optional>
#include "hw2.hpp"

struct TestBinaryTree {
   std::vector<std::optional<int>> inp;
   int sumOfNodes;
};

using std::nullopt;
std::vector<TestBinaryTree> testsBST = {
    {
        {
        8,
        4, 12,
        2, 6, 10, 14
        }, 2
    },
    {
        {
        15,
        7, 20,
        3, 9, 18, 25,
        nullopt, nullopt, 8, nullopt, nullopt, 19, nullopt, nullopt, nullopt
        }, 3 
    },
    {
        {
        10,
        8, nullopt,
        6, nullopt,
        4, nullopt,
        2, 5,
        1,nullopt,nullopt,nullopt 
        }, 11 
    },
    {
        {
        50,
        30, 70,
        20, 40, 60, 80,
        10, nullopt, nullopt, 45, nullopt, nullopt, nullopt, 90
        }, 90
    }
};

TEST_CASE("BST sum of nodes", "[sumOfNodes]") {
    for (auto tc : testsBST) {
        std::unique_ptr<TreeNode> tree(buildTree(tc.inp));
        auto res = sumOfNodes(tree.get());
        REQUIRE(res == tc.sumOfNodes);
    }
}