#include "project/recursive_algorithms.h"

#include <stdexcept>
#include <utility>
#include <vector>

// TODO: Implement factorial recursively.
// Base case: n == 0 or n == 1.
// Recursive case: n * factorial(n - 1).
int binarySearch(const std::vector<int>& array, int target, int left, int right) {
    if (left > right)
        return -1;
    int mid = left + (right - left) / 2;
    if (array[mid] == target)
        return mid;
    if (array[mid] > target)
        return binarySearch(array, target, left, mid - 1);
    return binarySearch(array, target, mid + 1, right);
}
  
int arraySum(const std::vector<int>& array, int index) {
    if (index == int(array.size()))         
        return 0;
    return array[index] + arraySum(array, index + 1);
}

void reverseHelper(std::vector<int>& array, int left, int right) {
    if (left >= right)                         // base case: 0 or 1 elements left
        return;
    std::swap(array[left], array[right]);
    reverseHelper(array, left + 1, right - 1);
}
int factorial(int n) {
    if (n < 0)
        throw std::invalid_argument("factorial: n must be non-negative");
    if (n <= 1)      // base case: 0! = 1! = 1
        return 1;
    return n * factorial(n - 1);
}


// TODO: Implement an iterative factorial comparison.
int factorialIterative(int n) {
    if (n < 0)
        throw std::invalid_argument("factorialIterative: n must be non-negative");
    int f = 1;
    for(int i=1;i<=n;i++){
        f = f*i;
    }
    return f;
}

// TODO: Implement fibonacci recursively.
// Base case: fib(0) = 0, fib(1) = 1.
// Recursive case: fib(n) = fib(n - 1) + fib(n - 2).
int fibonacci(int n) {
    if (n < 0)
        throw std::invalid_argument("fibonacci: n must be non-negative");
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

// TODO: Implement iterative fibonacci comparison.
int fibonacciIterative(int n) {
    if (n < 0)
        throw std::invalid_argument("fibonacciIterative: n must be non-negative");
    int a =0;
    int b =1;
    int sum;
    for(int i =0; i< n;i++){
        sum = a +b;
        a = b;
        b = sum;
    }
    return a;
}

// TODO: Implement recursive binary search on a sorted array.
// Base case: target not found or left > right.
// Recursive case: compare middle element and recurse on the appropriate half.
int binarySearch(const std::vector<int>& array, int target) {
    int left = 0;
    int right = int(array.size()) - 1;
    return binarySearch(array, target, left, right);
}

// TODO: Implement iterative binary search comparison.
int binarySearchIterative(const std::vector<int>& array, int target) {
    int start = 0;
    int end = static_cast<int>(array.size()) - 1;
    while (start<= end) {
        int mid = start + (end - start) / 2;
        if (array[mid] == target)
            return mid;
        if (array[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

// TODO: Implement recursive array sum.
// Base case: empty array.
// Recursive case: first element + arraySum(rest-of-array).
int arraySum(const std::vector<int>& array) {
    return arraySum(array, 0);
}

// TODO: Implement iterative array sum comparison.
int arraySumIterative(const std::vector<int>& array) {
    int sum =0;
    for(int i =0;i< int(array.size());i++)
        sum+= array[i];
    return sum;
}

// TODO: Implement recursive in-place reversal.
// Base case: size <= 1.
// Recursive case: swap first and last elements, then recurse on the remaining middle.
void reverseArray(std::vector<int>& array) {
    reverseHelper(array, 0, static_cast<int>(array.size()) - 1);
}

// TODO: Implement iterative reverse comparison.
void reverseArrayIterative(std::vector<int>& array) {
    int left = 0;
    int right = static_cast<int>(array.size()) - 1;
    while (left < right) {
        std::swap(array[left], array[right]);
        left++;
        right--;
    }
}


 
