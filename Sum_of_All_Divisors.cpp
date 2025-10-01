#include <iostream>
#include <cmath>
using namespace std;

/*
    * @class Sum_of_All_Divisors
    * @brief Provides an optimized method to calculate the sum of all divisors of a given integer.
    *
    * Problem:
    * - Given an integer n, compute the sum of all numbers that divide n (including 1 and n itself).
    *
    * Method:
    *
    * sum_of_divisors(int n):
    * - Iterate from 1 to sqrt(n) only.
    * - For each i:
    *     - If i divides n, add i to the sum.
    *     - Add n/i to the sum if i != n/i (to avoid double-counting perfect squares).
    * - Return the total sum.
    *
    * Optimization:
    * - By iterating only up to sqrt(n), we consider both divisors i and n/i simultaneously.
    * - This reduces the time complexity from O(n) to O(√n).
    *
    * Time Complexity: O(√n)
    * Space Complexity: O(1)
    *
    * Example:
    * - Input: n = 36
    * - Divisors: 1, 2, 3, 4, 6, 9, 12, 18, 36
    * - Sum: 1+2+3+4+6+9+12+18+36 = 91
*/

class Sum_of_All_Divisors {
    public:
    int sum_of_divisors(int n) {
        int sum = 0;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                sum += i;
                if (i != n / i) sum += n / i;
            }
        }
        return sum;
    };
};

// Main Function
int main() {
    int result = Sum_of_All_Divisors().sum_of_divisors(3);
    cout << result;
    return 0;
}