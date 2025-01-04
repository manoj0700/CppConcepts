#include <iostream>
#include <vector>

/**
 * [ capture_clause ] ( parameter_list ) mutable throw_spec -> return_type {
 * body }
 *
 */

// Accepts lambda as a parameter
void printSum(std::function<int()> func) { std::cout << func() << std::endl; }

int main() {
    int a = 0;
    int b = 2;

    // Capturing the local variables to the function in the capture list
    auto sum = [a, b]() { return a + b; };

    // By Default lambda expession are constant we cannot modify the captured
    // variables. We should be using mutalbe specifier to change the values

    auto modified_sum = [a, b]() mutable { return a + ++b; };

    // std::cout << sum() << std::endl;
    // std::cout << modified_sum() << std::endl;

    printSum(modified_sum); // Outputs: 3

    // Captures each element of vector by reference
    std::vector<int> nums = {1, 2, 3, 4};
    std::for_each(nums.begin(), nums.end(), [](int& n) { n = n * 5; });

    for (auto i : nums) {
        std::cout << i << " ";
    }

	std::cout << std::endl;

    std::vector<int> nums_ = {3, 1, 4, 1, 5};
    std::sort(nums_.begin(), nums_.end(), [](int a, int b) { return a > b; });
    for (int n : nums_)
        std::cout << n << " ";
    // Outputs: 5 4 3 1 1
}