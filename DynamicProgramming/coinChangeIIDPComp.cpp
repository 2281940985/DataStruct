#include<iostream>
#include<vector>
using namespace std;

int CoinChangeII_DPComp(vector<int> &coins, int amt)
{
    vector<int> dp(amt+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= coins.size(); i++)
    {
        for(int j = 1; j <= amt; ++j)
        {
            if(coins[i-1] > j)//硬币面值大于当前金额，不选择
            {
                dp[j] = dp[j];
            }
            else
            {
                dp[j] = dp[j] + dp[j-coins[i-1]];
            }
        }
    }
    return dp[amt];
}
int main()
{
    vector<int> coins = {1, 2, 5};
    int amt = 5;
    cout << CoinChangeII_DPComp(coins, amt) << endl;
    return 0;
}