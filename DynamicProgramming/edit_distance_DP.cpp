#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
���������ַ��� ? �� ? �����ؽ� ? ת��Ϊ ? ��������ٱ༭������
�������һ���ַ����н������ֱ༭����������һ���ַ���ɾ��һ���ַ������ַ��滻Ϊ����
һ���ַ���
*/
/*
״̬ [?, ?] ��Ӧ�������⣺�� ? ��ǰ ? ���ַ�����Ϊ ? ��ǰ ? ���ַ���������ٱ༭����
1. �� ?[? ? 1] ֮����� ?[? ? 1] ����ʣ�������� ??[?, ? ? 1] ��
2. ɾ�� ?[? ? 1] ����ʣ�������� ??[? ? 1, ?] ��
3. �� ?[? ? 1] �滻Ϊ ?[? ? 1] ����ʣ�������� ??[? ? 1, ? ? 1] ��

*/
int EditDistanceDP(string s, string t)
{
    vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, 0));
    //��ʼ������
    for(int i=1; i<=s.length(); i++)
    {
        dp[i][0] = i;
    }
    //��ʼ������
    for(int i=1; i<=t.length(); i++)
    {
        dp[0][i] = i;
    }
    //״̬ת�ƣ������к���
    for(int i = 1; i <= s.length(); i++)
    {
        for(int j = 1; j <= t.length(); j++)
        {
            if(s[i-1] == t[j-1])//β��ĸ��ͬ������Ҫִ�в�����ֱ���ж�ǰ����ĸ
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j])+1;
            }
        }
    }
    return dp[s.length()][t.length()];
}
int main()
{
    string bag = "bag";
    string pack = "pack";
    cout<<EditDistanceDP(bag, pack)<<endl;
    return 0;
}