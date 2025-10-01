#include <iostream>
#include <cmath>
using namespace std;

/*
    * @class isPrime
    * @brief Provides methods to check whether a given integer is prime.
    *
    * This class implements two approaches:
    *
    * 1. BruteForce_Approach(int n):
    *    - Iterates from 1 to n, counting divisors.
    *    - A number is prime if it has exactly 2 divisors (1 and itself).
    *    - Time Complexity: O(n).
    *    - Space Complexity: O(1).
    *
    * 2. Optimal_Approach(int n):
    *    - Iterates only up to sqrt(n), counting divisors.
    *    - If n is divisible by i, it accounts for both i and n/i.
    *    - A number is prime if divisor count equals 2.
    *    - Time Complexity: O(√n).
    *    - Space Complexity: O(1).
    *
    * Both methods return true if the number is prime, otherwise false.
*/

class isPrime {
public:
    bool BruteForce_Approach(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) count++;
        };

        if (count == 2) return true;
        return false;
    };

    bool Optimal_Approach(int n) {
        int count = 0;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                count++;
                if (n / i != i) count++;
            }
        };

        if (count == 2) return true;
        return false;
    };
};

// Main Function
int main()
{
    bool r1 = isPrime().BruteForce_Approach(175);
    bool r2 = isPrime().Optimal_Approach(1000000084);
    cout << r1 << endl;
    cout << r2 << endl;
    return 0;
}