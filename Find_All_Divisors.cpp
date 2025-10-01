#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
    * @class Solution
    * @brief Provides methods to compute all divisors of a given integer.
    *
    * This class implements two approaches for finding divisors of an integer `n`:
    *
    * 1. BruteForce(int n):
    *    - Iterates from 1 to n, checking divisibility.
    *    - Time Complexity: O(n)
    *    - Space Complexity: O(k), where k is the number of divisors.
    *
    * 2. OptimalApproach(int n):
    *    - Iterates up to sqrt(n), adding both divisors (i and n/i) for each valid divisor.
    *    - Skips duplicates when n is a perfect square.
    *    - Time Complexity: O(√n)
    *    - Space Complexity: O(k), where k is the number of divisors.
    *
    * Both methods return a vector containing all divisors of n.
*/

class Solution {
    vector<int> BruteForce(int n) {
        vector<int> divisors;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) divisors.push_back(i);
        }

        return divisors;
    }

    vector<int> OptimalApproach(int n) {
        vector<int> divisors;

        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) divisors.push_back(i);
            if (i != n / i && n % i == 0) divisors.push_back(n / i);
        }

        return divisors;
    }
};