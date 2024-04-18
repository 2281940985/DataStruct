#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int KnapsackDPComp(vector<int> &weights, vector<int> &values, int cap)
{
    vector<int> dp(cap+1, 0);
    for(int i = 1; i <= weights.size(); ++i)
    {
        for(int c = cap; c >= 1; --c)//必须使用倒序遍历，否则dp表之前的值会被覆盖,得不到正确结果
        {
            if(weights[i-1] <= c)
            {
                dp[c] = max(dp[c], dp[c-weights[i-1]] + values[i-1]);//注意这里是dp[c]不是dp[c-1],因为如果选择不放入新物品，容量并没有变化，因此不需要赋值dp[c-1]
            }
        }
        
    }
    return dp[cap];
}
int main()
{
    vector<int> weights = {1, 2, 3, 4, 5};
    vector<int> values = {10, 4, 3, 4, 5};
    int cap = 5;
    cout << KnapsackDPComp(weights, values, cap) << endl;
    return 0;
}