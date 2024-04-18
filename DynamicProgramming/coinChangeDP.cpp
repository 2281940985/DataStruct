#include<iostream>
#include<vector>
#include<algorithm>
#define INT_MAX 10000
using namespace std;
/*
���� ? ��Ӳ�ң��� ? ��Ӳ�ҵ���ֵΪ ?????[? ? 1] ��Ŀ����Ϊ ??? ��ÿ��Ӳ�ҿ����ظ�ѡ
ȡ�����ܹ��ճ�Ŀ���������Ӳ������������޷��ճ�Ŀ����򷵻� ?1 ��
*/
int CoinChangeDP(vector<int> &coins, int amt)
{
    //����dp��
    vector<vector<int>> dp(coins.size()+1, vector<int>(amt+1, 0));
    //��Ŀ����Ϊ 0 ʱ���ճ���������Ӳ������Ϊ 0 ������������ ??[?, 0] ������ 0�����Բ��õ�����ֵ
/*����Ӳ��ʱ���޷��ճ����� > 0 ��Ŀ���������Ч�⡣Ϊʹ״̬ת�Ʒ����е� min() �����ܹ�ʶ��
������Ч�⣬���ǿ���ʹ��10000����ʾ���ǣ������������� ??[0, ?] ������10000,�����Ҫ������ֵ*/
    for(int i = 1; i < amt+1; i++)
    {
        dp[0][i] = INT_MAX;
    }
    for(int i = 1; i <= coins.size(); i++)
    {
        for(int j = 1; j <= amt; j++)
        {
            if(coins[i-1] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]] + 1);
            }
        }
    }

    return dp[coins.size()][amt];

}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amt = 11;
    cout << CoinChangeDP(coins, amt) << endl;
    return 0;
}