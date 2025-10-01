#include <iostream>
using namespace std;

/*
    * @class PalindromeNumber
    * @brief Provides a method to check if a given integer is a palindrome.
    *
    * This class implements an optimal approach:
    *
    * - Optimal_Approach(int num):
    *   - Immediately returns false if the number is negative (since negatives can’t be palindromes).
    *   - Returns true if the number is 0.
    *   - For positive numbers, it reverses the digits and compares the reversed number
    *     with the original.
    *   - If both match, the number is a palindrome.
    *
    * Time Complexity: O(d), where d is the number of digits.
    * Space Complexity: O(1).
    *
    * @return true if the number is a palindrome, false otherwise.
*/

class PalindromeNumber {
public:
    bool Optimal_Approach(int num) {
        // if number is negative, it is not a palindrome
        if (num < 0) return false;

        // if number is 0, it's a palindrome
        if (num == 0) return true;

        // if number is positive
        if (num > 0) {
            int original_num = num;
            int rev_num = 0;

            // reverse the number
            while (num > 0) {
                int digit = num % 10;
                num /= 10;
                rev_num = rev_num * 10 + digit;
            }

            return original_num == rev_num;
        }
    }
};

// Main Function
int main() {
    bool result = PalindromeNumber().Optimal_Approach(-121);
    cout << result;
    return 0;
}