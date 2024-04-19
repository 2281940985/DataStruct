#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
输入两个字符串 ? 和 ? ，返回将 ? 转换为 ? 所需的最少编辑步数。
你可以在一个字符串中进行三种编辑操作：插入一个字符、删除一个字符、将字符替换为任意
一个字符。
*/
/*
状态 [?, ?] 对应的子问题：将 ? 的前 ? 个字符更改为 ? 的前 ? 个字符所需的最少编辑步数
1. 在 ?[? ? 1] 之后添加 ?[? ? 1] ，则剩余子问题 ??[?, ? ? 1] 。
2. 删除 ?[? ? 1] ，则剩余子问题 ??[? ? 1, ?] 。
3. 将 ?[? ? 1] 替换为 ?[? ? 1] ，则剩余子问题 ??[? ? 1, ? ? 1] 。

*/
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
            if(s[i-1] == t[j-1])//尾字母相同，不需要执行操作，直接判断前面字母
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