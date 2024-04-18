#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
给定 ? 个物品，第 ? 个物品的重量为 ???[? ? 1]、价值为 ???[? ? 1] ，和一个容量为 ??? 的
背包。每个物品可以重复选取，问在限定背包容量下能放入物品的最大价值。示例如图 14?22
所示。
*/
int UnboundedKnapsack(vector<int> &weights, vector<int> &values, int cap)
{
    //创建dp表
    vector<vector<int>> dp(weights.size()+1, vector<int>(cap+1, 0));
    for(int i = 1; i <= weights.size(); ++i)//遍历商品
    {
        for(int c = 1; c <= cap; c++)//遍历背包容量
        {
            if(weights[i-1] > c)
            {
                dp[i][c] = dp[i-1][c];
            }
            else
            {
                dp[i][c] = max(dp[i-1][c], dp[i][c-weights[i-1]] + values[i-1]);
            }
        }
    }
    return dp[weights.size()][cap];//最后输出我们需要的结果(右下角的dp元素)
}
int main()
{
    vector<int> weights = {10,20,30,40,50};
    vector<int> values = {50,120,150,210,240};
    cout << UnboundedKnapsack(weights, values,50) << endl;
    return 0;
}