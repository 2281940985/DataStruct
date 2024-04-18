#include<iostream>
#include<vector>
#include<algorithm>
#define INT_MAX 10000
using namespace std;
/*
给定 ? 种硬币，第 ? 种硬币的面值为 ?????[? ? 1] ，目标金额为 ??? ，每种硬币可以重复选
取，问能够凑出目标金额的最少硬币数量。如果无法凑出目标金额，则返回 ?1 。
*/
int CoinChangeDP(vector<int> &coins, int amt)
{
    //创建dp表
    vector<vector<int>> dp(coins.size()+1, vector<int>(amt+1, 0));
    //当目标金额为 0 时，凑出它的最少硬币数量为 0 ，即首列所有 ??[?, 0] 都等于 0，可以不用单独赋值
/*当无硬币时，无法凑出任意 > 0 的目标金额，即是无效解。为使状态转移方程中的 min() 函数能够识别并
过滤无效解，我们考虑使用10000来表示它们，即令首行所有 ??[0, ?] 都等于10000,这个需要单独赋值*/
    for(int i = 1; i < amt+1; i++)
    {
        dp[0][i] = INT_MAX;
    }
    for(int i = 1; i <= coins.size(); i++)
    {
        for(int j = 1; j <= amt; j++)
        {
            if(coins[i-1] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
            }
        }
    }

    return dp[coins.size()][amt];

}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amt = 11;
    cout << CoinChangeDP(coins, amt) << endl;
    return 0;
}