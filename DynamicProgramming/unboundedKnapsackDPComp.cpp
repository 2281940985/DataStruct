#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int UnboundedKnapsackDPComp(vector<int> &weights, vector<int> &values, int cap)
{
    //����dp��
    vector<int> dp(cap+1, 0);
    for(int i = 1; i <= weights.size(); ++i)
    {
        /*
���ڵ�ǰ״̬�Ǵ���ߺ��ϱߵ�״̬ת�ƶ����ģ���˿ռ��Ż���Ӧ�ö� ?? ���е�ÿһ�н������������
�������˳���� 0?1 ���������෴��
        */
        for(int c = 1; c <= cap; ++c)
        {
            if(weights[i-1] > c)
            {
                dp[c] = dp[c];
            }
            else
            {
                dp[c] = max(dp[c], dp[c-weights[i-1]]+values[i-1]);
            }
        }
    }
    return dp[cap];
}
int main()
{
    vector<int> weights = {10,20,30,40,50};
    vector<int> values = {50,120,150,210,240};
    cout << UnboundedKnapsackDPComp(weights, values,50) << endl;
    return 0;
}