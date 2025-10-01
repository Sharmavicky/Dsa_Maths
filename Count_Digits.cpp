#include <iostream>
#include <cmath>
using namespace std;

/*
    * @class CountDigits
    * @brief Provides methods to count the number of digits in a given integer.
    *
    * This class implements two approaches:
    *
    * 1. BruteForce_Approach(int num):
    *    - Iteratively divides the number by 10 until it becomes 0.
    *    - Increments a counter at each step.
    *    - Time Complexity: O(d), where d is the number of digits.
    *    - Space Complexity: O(1).
    *
    * 2. Optimal_Approach(int num):
    *    - Uses the mathematical property: digits = floor(log10(num)) + 1.
    *    - Achieves constant-time computation.
    *    - Time Complexity: O(1).
    *    - Space Complexity: O(1).
    *
    * Both methods return the count of digits in the integer.
*/

class CountDigits {
public:
    int BruteForce_Approach(int num) {
        int count = 0;
        while (num > 0) {
            count++;
            num /= 10;
        }
        return count;
    };

    int Optimal_Approach(int num) {
        int count = log10(num) + 1;
        return count;
    }
};
