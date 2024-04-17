#include<iostream>
#include<vector>

using namespace std;
/*
爬到第 ? ? 1 阶的方案数加上爬到第 ? ? 2 阶的方案数就等于爬到第 ? 阶的方案数。公式如下：
??[?] = ??[? ? 1] + ??[? ? 2], ??[1] = 1、??[2] = 2
*/

int Dfs(int i)
{
    if(i == 1 || i == 2)
    {
        return i;
    }
    return Dfs(i-1) + Dfs(i-2);//每一个都会被分解成两个小问题，时间复杂度为 ?(2^n)
}/*指数阶的时间复杂度是“重叠子问题”导致的。例如 ??[9] 被分解为 ??[8] 和 ??[7] ，??[8]
被分解为 ??[7] 和 ??[6] ，两者都包含子问题 ??[7] 。*/
int ClimbStairs(int n)
{
    cout << Dfs(n) << endl;
}
int main()
{
    ClimbStairs(4);
    return 0;
}