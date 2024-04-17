#include<iostream>
#include<vector>
#include<string>
using namespace std;

void BackTrack(int row, int n, vector<vector<string>> &state, vector<vector<vector<string>>> &res,
 vector<bool> &cols, vector<bool> &diags1, vector<bool> &diags2)
{
    // 当放置完所有行时，记录解
    if(row == n)
    {
        res.push_back(state);
        return;
    }
    //遍历所有列
    for(int col = 0; col < n; col++)
    {
        //主要思路将主对角线和次对角线关于row和col对应起来
        int diag1 = row - col + n-1;//主对角线差为固定值
        int diag2 = row + col;//次对角线和为固定值
        //剪枝：不允许该格子所在列、主对角线、次对角线上存在皇后
        if(cols[col]==false && diags1[diag1]==false && diags2[diag2]==false)
        {
            cols[col] = true;
            diags1[diag1] = true;
            diags2[diag2] = true;//更新状态
            state[row][col] = "Q";//放置皇后
            BackTrack(row+1, n, state, res, cols, diags1, diags2);
            //回退：将该格子恢复为空位
            state[row][col] = "#";
            cols[col] =diags1[diag1] = diags2[diag2] = false;
        }
    }
}
//求解n皇后
vector<vector<vector<string>>> NQueens(int n)
{
    vector<vector<string>> state(n, vector<string>(n, "#"));//二重数组这样初始化，初始化棋盘全部为'#'
    vector<bool> cols(n,false);
    vector<bool> diags1(2 * n - 1, false);//初始化主对角线和次对角线
    vector<bool> diags2(2 * n - 1, false);
    vector<vector<vector<string>>> res;
    BackTrack(0, n, state, res, cols, diags1, diags2);
    return res;
}

int main()
{
    int n = 5;
    vector<vector<vector<string>>> res = NQueens(n);
    for(auto &v2 : res)
    {
        for(auto &v1 : v2)
        {
            for(auto &v : v1)
            {
                cout << v << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}