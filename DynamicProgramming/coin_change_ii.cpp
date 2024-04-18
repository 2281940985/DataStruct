#include<iostream>
#include<vector>

using namespace std;
/*
给定 ? 种硬币，第 ? 种硬币的面值为 ?????[? ? 1] ，目标金额为 ??? ，每种硬币可以重复选
取，问凑出目标金额的硬币组合数量。
当目标金额为 0 时，无须选择任何硬币即可凑出目标金额，因此应将首列所有 ??[?, 0] 都初始化为 1 。当无
硬币时，无法凑出任何 > 0 的目标金额，因此首行所有 ??[0, ?] 都等于 0 。
*/
int CoinChangeII(vector<int> &coins, int amt)
{
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amt+1, 0));
    for(int i = 0; i <= coins.size(); i++)//dp表存储的是前 ? 种硬币能够凑出金额 ? 的组合数量。
    {
        dp[i][0] = 1;
    }
    for(int i = 1; i <= coins.size(); i++)
    {
        for(int j = 1; j <= amt; j++)
        {
            if(coins[i-1] > j)// 若超过目标金额，则不选硬币 i
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];// 不选和选硬币 i 这两种方案之和
            }

        }
    }
    return dp[coins.size()][amt];
   
}
int main()
{
    vector<int> coins = {1, 2, 5};
    int amt = 5;
    cout << CoinChangeII(coins, amt) << endl;
    return 0;
}
