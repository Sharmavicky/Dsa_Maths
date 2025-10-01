#include <iostream>
using namespace std;

/*
    * @class GCD
    * @brief Provides multiple approaches to compute the Greatest Common Divisor (GCD) of two integers.
    *
    * This class demonstrates different techniques to calculate the GCD:
    *
    * 1. BruteForce_Approach(int a, int b):
    *    - Iterates from 1 to min(a, b) and checks divisibility.
    *    - Stores the largest divisor found.
    *    - Time Complexity: O(min(a, b)).
    *    - Space Complexity: O(1).
    *
    * 2. Better_Approach(int a, int b):
    *    - Iterates from min(a, b) down to 1.
    *    - Returns the first divisor that divides both numbers.
    *    - Time Complexity: O(min(a, b)), but often faster due to early return.
    *    - Space Complexity: O(1).
    *
    * 3. Optimal_Approach(int a, int b):
    *    - Uses the Euclidean Algorithm (repeated modulo operation).
    *    - Significantly reduces the number of steps.
    *    - Time Complexity: O(log(min(a, b))).
    *    - Space Complexity: O(1).
    *
    * All methods return the GCD of the two integers.
*/

class GCD {
public:
    int BruteForce_Approach(int a, int b) { 
        int gcd = 1;
        for (int i = 1; i <= min(a, b); i++) {
            if (a % i == 0 && b % i == 0) gcd = i;
        }
        return gcd;
    };

    int Better_Approach(int a, int b) {
        for (int i = min(a, b); i >= 1; i--) {
            if (a % i == 0 && b % i == 0) return i;
        };
    };

    int Optimal_Approach(int a, int b) {
        while (a > 0 && b > 0) {
            if (a > b) a = a % b;
            else b = b % a;
        }

        if (a == 0) return b;
        return a;
    };
}; 