#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int dfs(vector<int>& coins, int amount) {
    if (amount == 0) {
        return 0;
    }

    int minCoins = INT_MAX;
    for (int coin : coins) {
        if (amount - coin >= 0) {
            int subProblem = dfs(coins, amount - coin);
            if (subProblem == -1) {
                continue; // Skip invalid subproblems
            }
            minCoins = min(minCoins, subProblem + 1);
        }
    }

    return (minCoins == INT_MAX) ? -1 : minCoins;
}

int coinChange(vector<int>& coins, int amount) {
    if (amount < 1) {
        return 0;
    }
    return dfs(coins, amount);
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 4;
    int minCoins = coinChange(coins, amount);
    cout << "Minimum number of coins needed: " << minCoins << endl;
    return 0;
}
