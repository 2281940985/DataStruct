#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int EditDistanceDP(string s, string t)
{
    vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, 0));
    //初始化首列
    for(int i=1; i<=s.length(); i++)
    {
        dp[i][0] = i;
    }
    //初始化首行
    for(int i=1; i<=t.length(); i++)
    {
        dp[0][i] = i;
    }
    //状态转移，其余行和列
    for(int i = 1; i <= s.length(); i++)
    {
        for(int j = 1; j <= t.length(); j++)
        {
            if(s[i-1] == t[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j])+1;
            }
        }
    }
    return dp[s.length()][t.length()];
}
int main()
{
    string bag = "bag";
    string pack = "pack";
    cout<<EditDistanceDP(bag, pack)<<endl;
    return 0;
}