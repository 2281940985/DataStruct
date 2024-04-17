#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//最小路径动态规划
int MinPathSumDp(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[0][0] = grid[0][0];
    //遍历首行
    for(int i = 1; i < col; i++)
    {
        dp[0][i] = dp[0][i-1] + grid[0][i];
    }
    //遍历首列
    for(int i = 1; i < row; i++)
    {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    //通过刚刚保存的首行和首列元素，计算其他元素
    for(int i = 1; i < row; ++i)
    {
        for(int j = 1; j < col; j++)
        {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    //最后返回dp表中的右下角元素，以为此时dp表中的元素已经保存了从最左上角到该位置最小路径
    return dp[row-1][col-1];
}
int main()
{
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << MinPathSumDp(grid) << endl;
    return 0;
}