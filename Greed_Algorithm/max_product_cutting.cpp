#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
����һ�������� ? �������з�Ϊ���������������ĺͣ����зֺ����������ĳ˻�����Ƕ��٣�
*/
int MaxProductCutting(int n)
{
    if(n <= 3)
    {
        return 1 * (n-1);
    }
    int a = n/3;
    int b = n%3;
    if(b == 1)
    {
        return pow(3,a-1) * 2 * 2;//������Ϊ 1 ʱ������ 2 �� 2 > 1 �� 3 �����Ӧ�����һ�� 3 �滻Ϊ 2 ��
    }
    else if(b == 0)
    {
        return pow(3,a);
    }
    else 
    {
        return pow(3,a) * b;
    }
}
/*̰�Ĳ���:
1. �������� ? �����䲻�ϵ��зֳ����� 3 ��ֱ������Ϊ 0��1��2 ��
2. ������Ϊ 0 ʱ������ ? �� 3 �ı�������˲����κδ���
3. ������Ϊ 2 ʱ�����������֣�������
4. ������Ϊ 1 ʱ������ 2 �� 2 > 1 �� 3 �����Ӧ�����һ�� 3 �滻Ϊ 2 ��
*/
int main()
{
    cout << MaxProductCutting(10) << endl;
    return 0;
}

