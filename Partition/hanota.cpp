#include <iostream>
#include <vector>

using namespace std;

//移动一个圆盘
void Move(vector<int> &src, vector<int> &tar)
{
    int top = src.back();
    src.pop_back();
    tar.push_back(top);
}

//移动n个圆盘和n-1个完全一样，只不过移动n个圆盘是将n-1个圆盘移动到buf，然后移动一个圆盘到tar，再将n-1个圆盘移动到tar即可
void Dfs(int i, vector<int> &src, vector<int> &buf, vector<int> &tar)
{
    if(i == 1)
    {
        Move(src, tar);//只剩一个圆盘直接做一次移动即可
        return;
    }
    Dfs(i - 1, src, tar, buf);//注意这里的buf和tar的位置,移动n-1个圆盘到buf
    Move(src, tar);//将最后一个圆盘移动到tar
    Dfs(i - 1, buf, src, tar);//将Buffer处的n-1个圆盘移动到tar
}
//求解汉诺塔
void SolveHanota(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int n = A.size();
    Dfs(n, A, B, C);
}
int main()
{
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B;
    vector<int> C;
    SolveHanota(A, B, C);
    for(int i = 0; i < C.size(); i++)
    {
        cout << C[i] << " ";
    }
    cout << endl;
    return 0;
}