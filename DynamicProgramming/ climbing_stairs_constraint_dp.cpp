#include<iostream>
#include<vector>

using namespace std;
/*
给定一个共有 ? 阶的楼梯，你每步可以上 1 阶或者 2 阶，但不能连续两轮跳 1 阶，请问有多
少种方案可以爬到楼顶？
*/
int ClimbingStairsConstraintDP(int n)
{
    if(n == 1 || n == 2)
    {
        return 1;
    }
    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[2][1] = 0;
    dp[2][2] = 1;
    for(int i = 3; i <= n; ++i)
    {
        dp[i][1] = dp[i-1][2];
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
    }
    return dp[n][1] + dp[n][2];
}

int main()
{
    int n = 5;
    cout << ClimbingStairsConstraintDP(n) << endl;
    return 0;
}