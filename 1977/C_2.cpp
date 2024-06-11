#include <iostream>
#include <vector>
#include <algorithm> // for std::gcd in C++17
#include <numeric>   // for std::accumulate

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the least common multiple (LCM) of two numbers
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// Function to calculate the LCM of a vector of numbers
int lcmOfVector(const std::vector<int>& nums) {
    // Use std::accumulate to apply lcm function across the vector
    return std::accumulate(nums.begin(), nums.end(), 1, lcm);
}

int main() {
    std::vector<int> nums = {12, 15, 20, 25};

    int result = lcmOfVector(nums);

    std::cout << "The LCM of the numbers is: " << result << std::endl;

    return 0;
}
