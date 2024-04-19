#include <iostream>
#include <vector>

using namespace std;

int CoinChangeGreedy(vector<int> &coins, int amt)
{
    int i = coins.size() - 1;
    int count = 0;
    while(amt && i >= 0)
    {
        if(coins[i] <= amt)
        {
            amt -= coins[i];
            count++;
        }
        else
        {
            i--;
        }
    }
    return count;
}
int main()
{
    vector<int> coins = {1, 5, 10, 20, 50, 100};
    int amt = 131;
    cout << CoinChangeGreedy(coins, amt);
    return 0;
}