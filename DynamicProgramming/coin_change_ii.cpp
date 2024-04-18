#include<iostream>
#include<vector>

using namespace std;
/*
���� ? ��Ӳ�ң��� ? ��Ӳ�ҵ���ֵΪ ?????[? ? 1] ��Ŀ����Ϊ ??? ��ÿ��Ӳ�ҿ����ظ�ѡ
ȡ���ʴճ�Ŀ�����Ӳ�����������
��Ŀ����Ϊ 0 ʱ������ѡ���κ�Ӳ�Ҽ��ɴճ�Ŀ������Ӧ���������� ??[?, 0] ����ʼ��Ϊ 1 ������
Ӳ��ʱ���޷��ճ��κ� > 0 ��Ŀ�������������� ??[0, ?] ������ 0 ��
*/
int CoinChangeII(vector<int> &coins, int amt)
{
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amt+1, 0));
    for(int i = 0; i <= coins.size(); i++)//dp��洢����ǰ ? ��Ӳ���ܹ��ճ���� ? �����������
    {
        dp[i][0] = 1;
    }
    for(int i = 1; i <= coins.size(); i++)
    {
        for(int j = 1; j <= amt; j++)
        {
            if(coins[i-1] > j)// ������Ŀ�����ѡӲ�� i
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];// ��ѡ��ѡӲ�� i �����ַ���֮��
            }

        }
    }
    return dp[coins.size()][amt];
   
}
int main()
{
    vector<int> coins = {1, 2, 5};
    int amt = 5;
    cout << CoinChangeII(coins, amt) << endl;
    return 0;
}
