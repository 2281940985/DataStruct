#include<iostream>
#include<vector>

using namespace std;
/*
������ ? ? 1 �׵ķ��������������� ? ? 2 �׵ķ������͵��������� ? �׵ķ���������ʽ���£�
??[?] = ??[? ? 1] + ??[? ? 2], ??[1] = 1��??[2] = 2
*/

int Dfs(int i)
{
    if(i == 1 || i == 2)
    {
        return i;
    }
    return Dfs(i-1) + Dfs(i-2);//ÿһ�����ᱻ�ֽ������С���⣬ʱ�临�Ӷ�Ϊ ?(2^n)
}/*ָ���׵�ʱ�临�Ӷ��ǡ��ص������⡱���µġ����� ??[9] ���ֽ�Ϊ ??[8] �� ??[7] ��??[8]
���ֽ�Ϊ ??[7] �� ??[6] �����߶����������� ??[7] ��*/
int ClimbStairs(int n)
{
    cout << Dfs(n) << endl;
}
int main()
{
    ClimbStairs(4);
    return 0;
}