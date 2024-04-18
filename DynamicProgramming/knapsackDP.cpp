#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int KnapsackDP(vector<int> &weights, vector<int> &values, int cap)
{
    vector<vector<int>> dp(weights.size()+1, vector<int>(cap+1, 0));//����dp����Ϊdp[0][c] = dp[i][0] = 0,���Ա�����1��ʼ����
    for(int i = 1; i <= weights.size(); ++i)//����i,����Ʒ������,�������ɷ����i����Ʒ���������������Ǵ�0��ʼ�ģ�������������Ҫ-1
    {
        for(int c = 1; c <= cap; ++c)//����c,������������,���Ϊ�ڵ�ǰ��ƷΪi,��������Ϊc������£��ܷ������Ʒi������󱳰��������Ƕ��٣�����dp��
        {
            if(weights[i-1] > c)
            {
                dp[i][c] = dp[i-1][c];//�����Ʒ���������ڱ��������������ܷ��뱳��������dp[i][c] = dp[i-1][c]
            }
            else 
            {
                // ��ѡ��ѡ��Ʒ i �����ַ����Ľϴ�ֵ
                dp[i][c] = max(dp[i-1][c], dp[i-1][c-weights[i-1]] + values[i-1]);
            }
        }
    }
    return dp[weights.size()][cap];
}//ʱ�临�ӶȺͿռ临�Ӷȶ������� dp ��С�������� ?(? �� ???)
int main()
{
    vector<int> weights = {1, 2, 3, 4};
    vector<int> values = {1, 2, 3, 4};
    int cap = 5;
    cout << KnapsackDP(weights, values, cap) << endl;
    return 0;
}