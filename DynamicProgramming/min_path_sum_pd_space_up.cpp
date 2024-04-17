#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//最小路径动态规划

int minPathSumDPComp(vector<vector<int>>&grid) 
{
    int n = grid.size(), m = grid[0].size();
    //初始化dp表
    vector<int> dp(m);
    //状态转移：首行
    dp[0] = grid[0][0];
    for (int j = 1; j <m; j++) {
        dp[j] = dp[j-1] + grid[0][j];
    }
    //状态转移：其余行
    for (int i = 1; i <n; i++) {
    //状态转移：首列
        dp[0] = dp[0] +grid[i][0];
    //状态转移：其余列
    for (int j = 1;j < m; j++) {
        dp[j] = min(dp[j-1], dp[j])+ grid[i][j];
    }
    }
    return dp[m-1];
 }
 int main()
{
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << minPathSumDPComp(grid) << endl;
    return 0;
}