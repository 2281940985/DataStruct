#include<iostream>
#include<vector>
#include<algorithm>
#define INT_MAX 100000000
using namespace std;

int CoinChangeDPComp(vector<int> &coins, int amt)
{
    vector<int> dp(amt+1, INT_MAX);
    dp[0] = 0;//dp[i] = k,表示存储的是当前找零金额i的最小硬币数k
    for(int i = 1; i <= coins.size(); ++i)
    {
        for(int j = 1; j <= amt; ++j)
        {
            if(coins[i-1] > j)//硬币值大于找零金额，不选该硬币
            {
                dp[j] = dp[j];
            }
            else//硬币值小于等于找零金额，考虑是否选该硬币
            {
                dp[j] = min(dp[j], dp[j - coins[i-1]] + 1);
            }
        }
    }
    return dp[amt];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amt = 11;
    cout << CoinChangeDPComp(coins, amt) << endl;
    return 0;
}