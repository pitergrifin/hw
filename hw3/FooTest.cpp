#include "hw.hpp"
#include <random>
#include <thread>
#include <iostream>

#define NUM_OF_ADD 100000

void threadFunc(int& sum, const std::vector<int>& vec) {
    for (auto el : vec)
        sum += el;
}

int main() {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(-100, 100);
    std::vector<int> numbers(NUM_OF_ADD);
    std::generate(numbers.begin(), numbers.end(), [&]() { return dist(gen); });

    Foo res;
    std::thread t1(threadFunc, std::ref(res.a), std::cref(numbers));
    std::thread t2(threadFunc, std::ref(res.b), std::cref(numbers));
    t1.join();
    t2.join();
    std::cerr << res.a << " " << res.b << "\n";
    return 0;
}