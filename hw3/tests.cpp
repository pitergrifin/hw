#include <catch2/catch_all.hpp>
#include <string>
#include <vector>
#include <memory>
#include <optional>
#include "hw.hpp"
#include "BinSearch.hpp"
#include "Heap.hpp"

TEST_CASE("BinarySearch", "[binSearch]") {
    std::vector<int> arr1 = {1, 3, 5, 7, 9};
    BinSearch<int> test1(arr1.begin(), arr1.end());
    REQUIRE(test1.find(1) == 0);
    REQUIRE(test1.find(9) == 4);
    REQUIRE(test1.find(5) == 2);
    REQUIRE(test1.find(2) == -1);

    std::vector<int> arr2 = {10};
    BinSearch<int> test2(arr2.begin(), arr2.end());
    REQUIRE(test2.find(10) == 0);
    REQUIRE(test2.find(5) == -1);
    
    std::vector<int> arr3;
    BinSearch<int> test3(arr3.begin(), arr3.end());
    REQUIRE(test3.find(1) == -1);

    std::vector<int> arr4 = {2, 4, 6, 8, 10, 12};
    BinSearch<int> test4(arr4.begin(), arr4.end());
    REQUIRE(test4.find(2) == 0);
    REQUIRE(test4.find(8) == 3);
    REQUIRE(test4.find(12) == 5);
    REQUIRE(test4.find(7) == -1);
}

TEST_CASE("Heap basic push and top", "[heap]") {
    Heap<int> h(std::less<int>{});
    REQUIRE(h.empty());

    h.push(10);
    REQUIRE_FALSE(h.empty());
    REQUIRE(h.top() == 10);

    h.push(5);
    REQUIRE(h.top() == 5);

    h.push(20);
    REQUIRE(h.top() == 5);

    h.push(1);
    REQUIRE(h.top() == 1);
}

TEST_CASE("Heap pop maintains min property", "[heap]") {
    Heap<int> h(std::less<int>{});
    h.push(10);
    h.push(4);
    h.push(15);
    h.push(1);

    REQUIRE(h.top() == 1);
    h.pop();
    REQUIRE(h.top() == 4);

    h.pop();
    REQUIRE(h.top() == 10);

    h.pop();
    REQUIRE(h.top() == 15);

    h.pop();
    REQUIRE(h.empty());
}

TEST_CASE("Heap handles duplicates", "[heap]") {
    Heap<int> h(std::less<int>{});
    h.push(5);
    h.push(5);
    h.push(5);

    REQUIRE(h.top() == 5);
    h.pop();
    REQUIRE(h.top() == 5);
    h.pop();
    REQUIRE(h.top() == 5);
    h.pop();
    REQUIRE(h.empty());
}

TEST_CASE("Basic examp for histogram", "[histogram]") {
    std::vector<int> vec{1, 1, 1, 1, 1, 1, 1, 5, 5, 6, 7, 8, 8, 8, 10};
    std::vector<std::pair<int, size_t>> res{{1, 7}, {5, 2}, {6, 1},
                                            {7, 1}, {8, 3}, {10, 1}};
    auto currRes = histogram(vec);
    REQUIRE(currRes == res);
}

TEST_CASE("empty vector produces empty histogram", "[histogram]") {
    std::vector<int> v;
    auto h = histogram(v);
    REQUIRE(h.empty());
}

TEST_CASE("single element vector", "[histogram]") {
    std::vector<int> v{42};
    auto h = histogram(v);
    REQUIRE(h.size() == 1);
    REQUIRE(h[0].first == 42);
    REQUIRE(h[0].second == 1);
}

TEST_CASE("all elements equal", "[histogram]") {
    std::vector<int> v(1000, 7); 
    auto h = histogram(v);
    REQUIRE(h.size() == 1);
    REQUIRE(h[0].first == 7);
    REQUIRE(h[0].second == 1000);
}

TEST_CASE("multiple groups", "[histogram]") {
    std::vector<int> v;
    v.insert(v.end(), 5, 1); 
    v.insert(v.end(), 3, 2); 
    v.insert(v.end(), 7, 3);  
    v.insert(v.end(), 2, 4); 

    auto h = histogram(v);
    REQUIRE(h.size() == 4);
    REQUIRE(h[0] == std::pair<int, std::size_t>{1, 5});
    REQUIRE(h[1] == std::pair<int, std::size_t>{2, 3});
    REQUIRE(h[2] == std::pair<int, std::size_t>{3, 7});
    REQUIRE(h[3] == std::pair<int, std::size_t>{4, 2});
}

TEST_CASE("already sorted with large runs", "[histogram]") {
    std::vector<int> v;
    for (int value = 1; value <= 100; ++value) {
        v.insert(v.end(), static_cast<std::size_t>(value), value);
    }
    auto h = histogram(v);
    REQUIRE(h.size() == 100);
    for (int value = 1; value <= 100; ++value) {
        REQUIRE(h[value - 1].first == value);
        REQUIRE(h[value - 1].second == static_cast<std::size_t>(value));
    }
}
