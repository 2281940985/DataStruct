#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int KnapsackDP(vector<int> &weights, vector<int> &values, int cap)
{
    vector<vector<int>> dp(weights.size()+1, vector<int>(cap+1, 0));//创建dp表，因为dp[0][c] = dp[i][0] = 0,所以遍历从1开始即可
    for(int i = 1; i <= weights.size(); ++i)//遍历i,即物品的数量,可以理解成放入第i个物品，但是在数组中是从0开始的，所以数组索引要-1
    {
        for(int c = 1; c <= cap; ++c)//遍历c,即背包的容量,理解为在当前物品为i,背包容量为c的情况下，能否放入物品i，放入后背包的容量是多少，更新dp表
        {
            if(weights[i-1] > c)
            {
                dp[i][c] = dp[i-1][c];//如果物品的重量大于背包的容量，则不能放入背包，所以dp[i][c] = dp[i-1][c]
            }
            else 
            {
                // 不选和选物品 i 这两种方案的较大值
                dp[i][c] = max(dp[i-1][c], dp[i-1][c-weights[i-1]] + values[i-1]);
            }
        }
    }
    return dp[weights.size()][cap];
}//时间复杂度和空间复杂度都由数组 dp 大小决定，即 ?(? × ???)
int main()
{
    vector<int> weights = {1, 2, 3, 4};
    vector<int> values = {1, 2, 3, 4};
    int cap = 5;
    cout << KnapsackDP(weights, values, cap) << endl;
    return 0;
}