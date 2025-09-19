#include <iostream>
#include <vector>
using namespace std;

/*
    This class provides two approaches to calculate Fibonacci numbers:

    1. withoutRecursion(int num):
       - Uses dynamic programming (bottom-up approach).
       - Stores results in a vector to avoid recomputation.
       - Time Complexity: O(n), Space Complexity: O(n).
       - Returns the (num-1)th Fibonacci number.

    2. withRecursion(int num):
       - Simple recursive approach.
       - Directly calls f(n-1) + f(n-2).
       - Time Complexity: O(2^n), Space Complexity: O(n) (due to recursion stack).
       - Demonstrates exponential time growth and inefficiency for large n.

    Note: Iterative/DP solution is efficient and preferred for large inputs,
          while recursion is good for understanding the problem structure.
*/

class Solution {
    public:
    int withoutRecursion(int num) {
        vector<int> fibo(num + 1);

        fibo[0] = 0;
        fibo[1] = 1;

        for (int i = 2; i < num + 1; i++){
            fibo[i] = fibo[i - 2] + fibo[i - 1];
        };

        return fibo[num - 1];
    }

    int withRecursion(int num) {
        if (num <= 1)
            return num;

        return withRecursion(num - 2) + withRecursion(num - 1);
    }
};

// main function
int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    int result = Solution().withRecursion(n);
    cout << result;

    return 0;
}