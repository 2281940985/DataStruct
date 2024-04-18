#include<iostream>
#include<vector>

using namespace std;
/*
����?����Ʒ����?����Ʒ������Ϊ???[??1]����ֵΪ???[??1]����һ������Ϊ???��
������ÿ����Ʒֻ��ѡ��һ�Σ������޶������������ܷ�����Ʒ������ֵ��
*/
//���ص��Ǽ�ֵ
int Knapsack(vector<int> &weights, vector<int> &values, int i, int c)
{
    //����ѡ��������Ʒ�򱳰���ʣ���������򷵻ؼ�ֵ 0
    if(i == 0 || c == 0)
    {
        return 0;
    }
    //����Ʒ��������������ֻ��ѡ�񲻷��� 
    if(weights[i-1] > c)
    {
        return Knapsack(weights, values, i-1, c);
    }
    //���㲻����ͷ�����Ʒ i ������ֵ
    int include = values[i-1] + Knapsack(weights, values, i-1, c-weights[i-1]);//������Ʒ�������������٣�������һ�ֵ���
    int declude = Knapsack(weights, values, i-1, c);//��������Ʒ���������������䣬������һ�ֵ���
    return max(include, declude);
    
}
int main()
{
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int c = 5;
    cout << Knapsack(weights, values, weights.size(), c) << endl;
    return 0;
}