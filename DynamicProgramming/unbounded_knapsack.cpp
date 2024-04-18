#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
���� ? ����Ʒ���� ? ����Ʒ������Ϊ ???[? ? 1]����ֵΪ ???[? ? 1] ����һ������Ϊ ??? ��
������ÿ����Ʒ�����ظ�ѡȡ�������޶������������ܷ�����Ʒ������ֵ��ʾ����ͼ 14?22
��ʾ��
*/
int UnboundedKnapsack(vector<int> &weights, vector<int> &values, int cap)
{
    //����dp��
    vector<vector<int>> dp(weights.size()+1, vector<int>(cap+1, 0));
    for(int i = 1; i <= weights.size(); ++i)//������Ʒ
    {
        for(int c = 1; c <= cap; c++)//������������
        {
            if(weights[i-1] > c)
            {
                dp[i][c] = dp[i-1][c];
            }
            else
            {
                dp[i][c] = max(dp[i-1][c], dp[i][c-weights[i-1]] + values[i-1]);
            }
        }
    }
    return dp[weights.size()][cap];//������������Ҫ�Ľ��(���½ǵ�dpԪ��)
}
int main()
{
    vector<int> weights = {10,20,30,40,50};
    vector<int> values = {50,120,150,210,240};
    cout << UnboundedKnapsack(weights, values,50) << endl;
    return 0;
}