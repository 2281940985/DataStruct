#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int KnapsackDPComp(vector<int> &weights, vector<int> &values, int cap)
{
    vector<int> dp(cap+1, 0);
    for(int i = 1; i <= weights.size(); ++i)
    {
        for(int c = cap; c >= 1; --c)//����ʹ�õ������������dp��֮ǰ��ֵ�ᱻ����,�ò�����ȷ���
        {
            if(weights[i-1] <= c)
            {
                dp[c] = max(dp[c], dp[c-weights[i-1]] + values[i-1]);//ע��������dp[c]����dp[c-1],��Ϊ���ѡ�񲻷�������Ʒ��������û�б仯����˲���Ҫ��ֵdp[c-1]
            }
        }
        
    }
    return dp[cap];
}
int main()
{
    vector<int> weights = {1, 2, 3, 4, 5};
    vector<int> values = {10, 4, 3, 4, 5};
    int cap = 5;
    cout << KnapsackDPComp(weights, values, cap) << endl;
    return 0;
}