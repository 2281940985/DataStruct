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
���� ??[?] ֻ�� ??[? ? 1] �� ??[? ? 2] �йأ������������ʹ��һ������ dp ����
������������Ľ⣬��ֻ��������������ǰ�����ɡ�����������ʾ��
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
}//ʡȥ������ dp ռ�õĿռ䣬��˿ռ临�Ӷȴ� ?(?) ���� ?(1) ��
/*
�ڶ�̬�滮�����У���ǰ״̬��������ǰ�����޸�״̬�йأ���ʱ���ǿ���ֻ������Ҫ��״̬��ͨ������ά��
����ʡ�ڴ�ռ䡣���ֿռ��Ż����ɱ���Ϊ�������������򡰹������顱��
*/

int main()
{
    int n;
    cin >> n;
    cout << ClimbingStarisDP2(n) << endl;
    return 0;
}