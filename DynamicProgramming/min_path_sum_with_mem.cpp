#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000

using namespace std;

int MinPathSumDfsMem(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &mem)
{
    if(i == 0 && j == 0)
    {
        return grid[0][0];
    }
    if(i < 0 || j < 0)
    {
        return INF;
    }
    if(mem[i][j] != INF)//初始化必须将所有的mem[][]赋值为INF，否则在经过这条语句判断后会直接返回mem[i][j]，而不会进入下面的递归
    {
        return mem[i][j];//碰到已近记录的结果后，直接返回即可
    }
    int up = MinPathSumDfsMem(grid, i-1, j, mem);
    int left = MinPathSumDfsMem(grid, i, j-1, mem);
    mem[i][j] = min(up, left) != INF ? min(up, left)+grid[i][j] : INF;//不用担心i=j=0怎么办，因为上面的判断已经处理了
    return mem[i][j];
}//在引入记忆化后，所有子问题的解只需计算一次，因此时间复杂度取决于状态总数，即网格尺寸 ?(??) 
int main()
{
    vector<vector<int>> grid = {{1,3,1}, {1,5,1}, {4,2,1}};
    vector<vector<int>> mem(3, vector<int>(3, INF));
    cout << MinPathSumDfsMem(grid, 2, 2, mem) << endl;
    return 0;
}