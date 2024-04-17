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
    if(mem[i][j] != INF)//��ʼ�����뽫���е�mem[][]��ֵΪINF�������ھ�����������жϺ��ֱ�ӷ���mem[i][j]���������������ĵݹ�
    {
        return mem[i][j];//�����ѽ���¼�Ľ����ֱ�ӷ��ؼ���
    }
    int up = MinPathSumDfsMem(grid, i-1, j, mem);
    int left = MinPathSumDfsMem(grid, i, j-1, mem);
    mem[i][j] = min(up, left) != INF ? min(up, left)+grid[i][j] : INF;//���õ���i=j=0��ô�죬��Ϊ������ж��Ѿ�������
    return mem[i][j];
}//��������仯������������Ľ�ֻ�����һ�Σ����ʱ�临�Ӷ�ȡ����״̬������������ߴ� ?(??) 
int main()
{
    vector<vector<int>> grid = {{1,3,1}, {1,5,1}, {4,2,1}};
    vector<vector<int>> mem(3, vector<int>(3, INF));
    cout << MinPathSumDfsMem(grid, 2, 2, mem) << endl;
    return 0;
}