#include<iostream>
#include<vector>
#include<algorithm>
#define INT_MAX 13232
using namespace std;
/*
����һ�� ? �� ? �Ķ�ά���� grid �������е�ÿ����Ԫ�����һ���Ǹ���������ʾ�õ�Ԫ��
�Ĵ��ۡ������������Ͻǵ�Ԫ��Ϊ��ʼ�㣬ÿ��ֻ�����»��������ƶ�һ����ֱ���������½�
��Ԫ���뷵�ش����Ͻǵ����½ǵ���С·���͡�
*/
//��������
int MInPathSumDfs(vector<vector<int>> &grid, int i, int j)
{
    // ��Ϊ���Ͻǵ�Ԫ������ֹ��
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