#include<iostream>
#include<vector>

using namespace std;

int ClimbingStarisDP(int n)
{
    if(n == 1 || n == 2)
    {
        return n;
    }
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
/*
由于 ??[?] 只与 ??[? ? 1] 和 ??[? ? 2] 有关，因此我们无须使用一个数组 dp 来存
储所有子问题的解，而只需两个变量滚动前进即可。代码如下所示：
*/
int ClimbingStarisDP2(int n)
{
    if(n == 1 || n == 2)
    {
        return n;
    }
    int a = 1, b = 2;
    for(int i = 3; i <= n; ++i)
    {
        int tmp = b;
        b = a + b;
        a = tmp;
    }
    return b;
}//省去了数组 dp 占用的空间，因此空间复杂度从 ?(?) 降至 ?(1) 。
/*
在动态规划问题中，当前状态往往仅与前面有限个状态有关，这时我们可以只保留必要的状态，通过“降维”
来节省内存空间。这种空间优化技巧被称为“滚动变量”或“滚动数组”。
*/

int main()
{
    int n;
    cin >> n;
    cout << ClimbingStarisDP2(n) << endl;
    return 0;
}