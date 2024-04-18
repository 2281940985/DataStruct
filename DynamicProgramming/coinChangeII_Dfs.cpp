#include<iostream>
#include<vector>
#include<algorithm>
#define INT_MAX 100000
using namespace std;

int Dfs(vector<int> &coins, int amt)
{
    if(amt == 0)
    {
        return 0;
    }
    int res = INT_MAX;
    for(int i = 0; i < coins.size(); i++)
    {
        if(amt >= coins[i])
        {
            int inc = 1 + Dfs(coins, amt - coins[i]);
            int exc = Dfs(coins, amt);
            res = min(inc, exc);
        }
        else
        {
            res = Dfs(coins, amt);
        }
    }
    return res;
    
}
int main()
{
    vector<int> coins = {1, 2, 5};
    cout << Dfs(coins, 4) << endl;
    return 0;
}