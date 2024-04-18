#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
//����������ȱ������õ���Ǯ�һ���������Ҫ����СӲ������
int CoinsChangeDfs(vector<int> &coins, int amt)
{
    //��������������
    if(amt == 0)
    {
        return 0;
    }
    //��Ҫ���ص�ֵ��ʼ��Ϊ�����������min�����������
    int res = INT_MAX;
    for(int i = 0; i < coins.size(); i++)//�������еı���
    {
        if(amt >= coins[i])//˵�������ڵ�ǰ���֣�����ѡ��ʹ�øñһ��߲�����
        {
            int inc = 1 + CoinsChangeDfs(coins, amt - coins[i]);//ʹ�øñң�Ӳ����������Ҫ��1���ٵݹ����Ŀ����Ϊamt - coins[i]
            //int exc = CoinsChangeDfs(coins, amt);//ǧ��������д����Ϊ�����ʾ��ʹ�øñң�Ӧֱ�ӷ��ص�ǰ�㼶�Ľ���������Ǽ����ݹ���ã�Ӧ��exc = res;
            res = min(inc, res);//res�ʹ���ʹ�øñ��֣���ԭ����״̬
        }
    }
    return res == INT_MAX ? -1 : res;
    
}
int main()
{
    vector<int> coins = {1, 2, 5};
    cout << CoinsChangeDfs(coins, 5) << endl;
    return 0;
}