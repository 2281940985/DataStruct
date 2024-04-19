#include<iostream>
#include<vector>

using namespace std;
/*
给定 ? 个物品，第 ? 个物品的重量为 ???[? ? 1]、价值为 ???[? ? 1] ，和一个容量为 ??? 的
背包。每个物品只能选择一次，但可以选择物品的一部分，价值根据选择的重量比例计算，问
在限定背包容量下背包中物品的最大价值。
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
                swap(items[j], items[j + 1]);//冒泡排序
            }
        }
    }
}
//分数背包
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
        if(cap >= item.weight)//因为每个物品只能选一次，所以优先放入单位重量价值最大的物品
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







