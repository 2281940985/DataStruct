#include<iostream>
#include<vector>
#include<algorithm>
#define INT_MAX 13232
using namespace std;
/*
给定一个 ? × ? 的二维网格 grid ，网格中的每个单元格包含一个非负整数，表示该单元格
的代价。机器人以左上角单元格为起始点，每次只能向下或者向右移动一步，直至到达右下角
单元格。请返回从左上角到右下角的最小路径和。
*/
//暴力搜索
int MInPathSumDfs(vector<vector<int>> &grid, int i, int j)
{
    // 若为左上角单元格，则终止搜
    if(i == 0 && j == 0)
    {
        return grid[0][0];
    }
    if(i < 0 || j < 0)
    {
        return INT_MAX;
    }
    int up = MInPathSumDfs(grid, i-1, j);
    int left = MInPathSumDfs(grid, i, j-1);
    return min(up, left) != INT_MAX ? min(up, left) + grid[i][j] : INT_MAX;
}
int main()
{
    vector<vector<int>> grid = {{1,3,1}, {1,5,1}, {4,2,1}};
    cout<<MInPathSumDfs(grid, 2, 2)<<endl;
    return 0;
}