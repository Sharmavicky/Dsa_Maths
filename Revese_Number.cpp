#include <iostream>
using namespace std;

/*
    * @class ReverseNumber
    * @brief Provides a method to reverse the digits of a given integer.
    *
    * This class implements a digit-reversal algorithm:
    *
    * - reverse_num(int num):
    *   - Extracts the last digit of the number using modulo operation.
    *   - Builds the reversed number by shifting existing digits and appending the last digit.
    *   - Repeats until the number becomes 0.
    *   - Time Complexity: O(d), where d is the number of digits.
    *   - Space Complexity: O(1).
    *
    * The method returns the integer obtained by reversing the digits of the input number.
*/

class ReverseNumber {
public:
    int reverse_num(int num) {
        int reversed = 0;
        while (num > 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }

        return reversed;
    };
};

// Main function
int main() {
    int result = ReverseNumber().reverse_num(10400);
    cout << result;
    return 0;
}