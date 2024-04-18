#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
//采用深度优先遍历来得到零钱兑换问题所需要的最小硬币数量
int CoinsChangeDfs(vector<int> &coins, int amt)
{
    //迭代跳出的条件
    if(amt == 0)
    {
        return 0;
    }
    //将要返回的值初始化为无穷大，这样在min函数方便过滤
    int res = INT_MAX;
    for(int i = 0; i < coins.size(); i++)//遍历所有的币种
    {
        if(amt >= coins[i])//说明金额大于当前币种，可以选择使用该币或者不适用
        {
            int inc = 1 + CoinsChangeDfs(coins, amt - coins[i]);//使用该币，硬币数量则需要加1，再递归调用目标金额为amt - coins[i]
            //int exc = CoinsChangeDfs(coins, amt);//千万不能这样写，因为这里表示不使用该币，应直接返回当前层级的结果，而不是继续递归调用，应当exc = res;
            res = min(inc, res);//res就代表不使用该币种，即原来的状态
        }
    }
    return res == INT_MAX ? -1 : res;
    
}
int main()
{
    vector<int> coins = {1, 2, 5};
    cout << CoinsChangeDfs(coins, 5) << endl;
    return 0;
}