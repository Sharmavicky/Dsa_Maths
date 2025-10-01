#include <iostream>
#include <cmath>
using namespace std;

/*
    * @class isArmstrongNumber
    * @brief Provides methods to check whether a given number is an Armstrong (narcissistic) number.
    *
    * Problem:
    * - An Armstrong number is an n-digit number such that the sum of its digits
    *   raised to the power n equals the number itself.
    *   Example: 153 → 1^3 + 5^3 + 3^3 = 153
    *
    * Methods:
    *
    * 1. BruteForce(int n):
    *    - Count the number of digits by repeatedly dividing n by 10.
    *    - For each digit, calculate digit^digits using pow() and sum them.
    *    - static_cast<int>(pow(digit, digits) + 0.5) is used to convert the floating-point
    *      result of pow() to an integer while avoiding precision errors.
    *      - pow() returns a double, which may not be exactly an integer due to floating-point
    *        arithmetic (e.g., pow(5,3) could be 124.9999999).
    *      - Adding 0.5 and casting to int ensures proper rounding to the nearest integer.
    *    - Return true if sum equals the original number.
    *
    * 2. OptimalApproach(int num):
    *    - Uses log10(num) + 1 to calculate the number of digits in O(1) instead of a loop.
    *    - Calculates the sum of digits^digits in the same way as BruteForce.
    *    - Returns true if the sum equals the original number.
    *
    * Time Complexity: O(d), where d = number of digits in the number.
    * Space Complexity: O(1)
    *
    * Example:
    * - Input: 153
    * - Output: true
*/

class isArmstrongNumber {
    public:
    bool BruteForce(int n) {
        int originalNum = n;
        int sum = 0;
        int digits = 0;

        // count the number of digits
        while (n > 0) {
            digits++;
            n /= 10;
        }

        n = originalNum;

        // calculate the sum of the digits raised to the power of number of digits
        while (n > 0) {
            int digit = n % 10;
            sum += static_cast<int>(pow(digit, digits) + 0.5);
            n /= 10;
        }

        return sum == originalNum;
    }

    int OptimalApproach(int num) {
        int originalNum = num;
        int sum = 0;
        int digits = log10(num) + 1; // count the number of digits

        while (num > 0) {
            int digit = num % 10;
            sum += static_cast<int>(pow(digit, digits) + 0.5);
            num /= 10;
        }

        return sum == originalNum;
    }
};

// main function
int main() {
    isArmstrongNumber obj;
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (obj.OptimalApproach(number)) {
        cout << number << " is an Armstrong number." << endl;
    } else {
        cout << number << " is not an Armstrong number." << endl;
    }

    return 0;
}