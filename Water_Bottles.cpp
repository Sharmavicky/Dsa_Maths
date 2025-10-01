#include <iostream>
using namespace std;

/*
    * @class Water_Bottles
    * @brief Solves the problem of maximizing the number of water bottles one can drink
    *        given an initial number of full bottles and a bottle-exchange system.
    *
    * Problem:
    * - You start with 'numBottles' full water bottles.
    * - You can exchange 'numExchange' empty bottles for 1 full bottle.
    * - Return the maximum number of bottles you can drink.
    *
    * Methods:
    *
    * 1. BruteForce(int numBottles, int numExchange):
    *    - Simulates the process of drinking and exchanging bottles step by step.
    *    - Keep track of total bottles drunk and empty bottles.
    *    - While empty bottles >= numExchange:
    *        - Exchange empty bottles for new full bottles.
    *        - Update totalDrank and remaining empty bottles.
    *    - Time Complexity: O(n), where n is the total number of bottles consumed.
    *    - Space Complexity: O(1).
    *
    * 2. OptimalApproach(int numBottles, int numExchange):
    *    - Uses a mathematical formula to directly calculate the total number of bottles drunk:
    *        totalDrank = numBottles + (numBottles - 1) / (numExchange - 1)
    *
    *    Explanation of formula:
    *    - Every 'numExchange' empty bottles give 1 new bottle.
    *    - Effectively, the number of additional bottles from exchanges is:
    *          extraBottles = floor((numBottles - 1) / (numExchange - 1))
    *      This works because after drinking the initial bottles, each new bottle reduces
    *      the number of empty bottles needed for the next exchange by 1.
    *    - Adding the initial bottles gives the total bottles drunk.
    *    - This eliminates the need for simulation and gives O(1) computation.
    *
    *    - Time Complexity: O(1)
    *    - Space Complexity: O(1)
    *
    * Both methods return the maximum number of bottles that can be drunk.
*/

class Water_Bottles {
    public:
    int BruteForce(int numBottles, int numExchange) {
        int totalDrank = numBottles;
        int emptyBottles = numBottles;

        while (emptyBottles >= numExchange) {
            int newBottles = emptyBottles / numExchange;
            totalDrank += newBottles;
            emptyBottles = emptyBottles % numExchange + newBottles;
        }

        return totalDrank;
    }

    int OptimalApproach(int numBottles, int numExchange) {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};

// main function
int main() {
    int res = Water_Bottles().OptimalApproach(9, 3);
    cout << res;
    return 0;
}