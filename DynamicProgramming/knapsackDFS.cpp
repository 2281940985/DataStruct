#include<iostream>
#include<vector>

using namespace std;
/*
给定?个物品，第?个物品的重量为???[??1]、价值为???[??1]，和一个容量为???的
背包。每个物品只能选择一次，问在限定背包容量下能放入物品的最大价值。
*/
//返回的是价值
int Knapsack(vector<int> &weights, vector<int> &values, int i, int c)
{
    //若已选完所有物品或背包无剩余容量，则返回价值 0
    if(i == 0 || c == 0)
    {
        return 0;
    }
    //若物品重量超过背包，只能选择不放入 
    if(weights[i-1] > c)
    {
        return Knapsack(weights, values, i-1, c);
    }
    //计算不放入和放入物品 i 的最大价值
    int include = values[i-1] + Knapsack(weights, values, i-1, c-weights[i-1]);//放入物品，背包容量减少，进入下一轮迭代
    int declude = Knapsack(weights, values, i-1, c);//不放入物品，，背包容量不变，进入下一轮迭代
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