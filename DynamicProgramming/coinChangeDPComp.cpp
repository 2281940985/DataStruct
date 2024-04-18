#include<iostream>
#include<vector>
#include<algorithm>
#define INT_MAX 100000000
using namespace std;

int CoinChangeDPComp(vector<int> &coins, int amt)
{
    vector<int> dp(amt+1, INT_MAX);
    dp[0] = 0;//dp[i] = k,��ʾ�洢���ǵ�ǰ������i����СӲ����k
    for(int i = 1; i <= coins.size(); ++i)
    {
        for(int j = 1; j <= amt; ++j)
        {
            if(coins[i-1] > j)//Ӳ��ֵ�����������ѡ��Ӳ��
            {
                dp[j] = dp[j];
            }
            else//Ӳ��ֵС�ڵ�������������Ƿ�ѡ��Ӳ��
            {
                dp[j] = min(dp[j], dp[j - coins[i-1]] + 1);
            }
        }
    }
    return dp[amt];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amt = 11;
    cout << CoinChangeDPComp(coins, amt) << endl;
    return 0;
}