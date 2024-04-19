#include<iostream>
#include<vector>

using namespace std;
/*
���� ? ����Ʒ���� ? ����Ʒ������Ϊ ???[? ? 1]����ֵΪ ???[? ? 1] ����һ������Ϊ ??? ��
������ÿ����Ʒֻ��ѡ��һ�Σ�������ѡ����Ʒ��һ���֣���ֵ����ѡ��������������㣬��
���޶����������±�������Ʒ������ֵ��
*/
class Item
{
public:
    int weight;
    int value;
    Item(int w, int v) : weight(w), value(v) {}
};
void SortItems(vector<Item> &items)
{
    for(int i = items.size() - 1; i >= 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if((double) items[j].value / items[j].weight < (double) items[j + 1].value / items[j + 1].weight)
            {
                swap(items[j], items[j + 1]);//ð������
            }
        }
    }
}
//��������
double FractionalKnapsack(vector<int> &weights, vector<int> &values, int cap)
{
    vector<Item> items;
    for(int i = 0; i < weights.size(); ++i)
    {
        items.push_back(Item(weights[i], values[i]));
    }
    SortItems(items);
    double res = 0;
    for(auto &item : items)
    {
        if(cap >= item.weight)//��Ϊÿ����Ʒֻ��ѡһ�Σ��������ȷ��뵥λ������ֵ������Ʒ
        {
            res += item.value;
            cap -= item.weight;
        }
        else
        {
            res += (double) item.value / item.weight * cap;
            break;
        }
    }
    return res;
}

int main()
{
    vector<int> weights = {10, 20, 30, 40, 50};
    vector<int> values = {50, 120, 150, 210, 240};
    int cap = 50;
    cout << FractionalKnapsack(weights, values, cap) << endl;
    return 0;
}







