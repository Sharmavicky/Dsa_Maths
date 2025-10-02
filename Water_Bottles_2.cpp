#include <iostream>
using namespace std;

/*
    * Problem: Given a number of full water bottles and an initial exchange rate,
    *          drink all the bottles and keep track of empty bottles. After every
    *          successful exchange, the exchange rate increases by 1.
    *
    * Example:
    *   Input: numBottles = 9, numExchange = 3
    *   Process: Drink 9 bottles (total = 9), exchange 3 empties for 1 new bottle,
    *            exchange rate increases to 4, and so on...
    *   Output: 11
    *
    * Approach:
    *   - Initialize totalDrank = numBottles, emptyBottles = numBottles.
    *   - While empty bottles >= current exchange requirement:
    *       * Exchange enough bottles for one new bottle.
    *       * Drink it, increase totalDrank.
    *       * Update empty bottles (subtract exchange cost, add 1 new empty).
    *       * Increase exchange requirement by 1.
    *   - Return totalDrank as the final result.
    *
    * Time Complexity: O(k), where k is the number of successful exchanges.
    * Space Complexity: O(1), since only counters are used.
*/

class Solution {
    public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrank = numBottles;
        int emptyBottles = numBottles;

        while (emptyBottles >= numExchange) {
            // drink one new bottle
            totalDrank++;

            // update empty bottles
            emptyBottles = emptyBottles - numExchange + 1;

            // increment the count of exchanged bottles
            numExchange++;
        }

        return totalDrank;
    }
};

// main funcion
int main() {
    Solution sol;
    int numBottles = 10;
    int numExchange = 3;

    cout << sol.numWaterBottles(numBottles, numExchange) << endl;

    return 0;
}