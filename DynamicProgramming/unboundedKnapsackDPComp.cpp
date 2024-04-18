#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int UnboundedKnapsackDPComp(vector<int> &weights, vector<int> &values, int cap)
{
    //创建dp表
    vector<int> dp(cap+1, 0);
    for(int i = 1; i <= weights.size(); ++i)
    {
        /*
由于当前状态是从左边和上边的状态转移而来的，因此空间优化后应该对 ?? 表中的每一行进行正序遍历。
这个遍历顺序与 0?1 背包正好相反。
        */
        for(int c = 1; c <= cap; ++c)
        {
            if(weights[i-1] > c)
            {
                dp[c] = dp[c];
            }
            else
            {
                dp[c] = max(dp[c], dp[c-weights[i-1]]+values[i-1]);
            }
        }
    }
    return dp[cap];
}
int main()
{
    vector<int> weights = {10,20,30,40,50};
    vector<int> values = {50,120,150,210,240};
    cout << UnboundedKnapsackDPComp(weights, values,50) << endl;
    return 0;
}