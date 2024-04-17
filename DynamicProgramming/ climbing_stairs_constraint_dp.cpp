#include<iostream>
#include<vector>

using namespace std;
/*
����һ������ ? �׵�¥�ݣ���ÿ�������� 1 �׻��� 2 �ף����������������� 1 �ף������ж�
���ַ�����������¥����
*/
int ClimbingStairsConstraintDP(int n)
{
    if(n == 1 || n == 2)
    {
        return 1;
    }
    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[2][1] = 0;
    dp[2][2] = 1;
    for(int i = 3; i <= n; ++i)
    {
        dp[i][1] = dp[i-1][2];
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
    }
    return dp[n][1] + dp[n][2];
}

int main()
{
    int n = 5;
    cout << ClimbingStairsConstraintDP(n) << endl;
    return 0;
}