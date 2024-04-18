#include<iostream>
#include<vector>
#include<algorithm>
#define INF -1
using namespace std;
/*
对于每个物品来说，不放入背包，背包容量不变；放入背包，背包容量减小。由此可得状态定义：当前物品
编号𝑖和剩余背包容量𝑐，记为[𝑖,𝑐]。
状态[𝑖,𝑐] 对应的子问题为：前𝑖个物品在剩余容量为𝑐的背包中的最大价值，记为𝑑𝑝[𝑖,𝑐]。
待求解的是𝑑𝑝[𝑛,𝑐𝑎𝑝]，因此需要一个尺寸为(𝑛+1)×(𝑐𝑎𝑝+1)的二维𝑑𝑝表。
*/
int KnapsackDfsWithMem(vector<int> &weights, vector<int> &values, vector<vector<int>> &mem, int i, int c)
{
    //若已选完所有物品或背包无剩余容量，则返回价值0
    if(i == 0 || c == 0)
    {
        return 0;
    }
    //若超过背包容量，则只能选择不放入背包
    if(weights[i-1] > c)
    {
        return KnapsackDfsWithMem(weights, values, mem, i-1, c);
    }
    //若已有记录，则直接返回
    if(mem[i][c] != INF)
    {
        return mem[i][c];
    }
    int include =values[i-1] + KnapsackDfsWithMem(weights, values, mem, i-1, c-weights[i-1]);
    int exclude = KnapsackDfsWithMem(weights, values, mem, i-1, c);
    mem[i][c] = max(include, exclude);//记录并返回两种方案中价值更大的那一个,不能写成i-1，因为这是记录当前状态
    return mem[i][c];
}
int main()
{
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 110, 120};
    int c = 30;
    vector<vector<int>> mem(weights.size()+1, vector<int>(c+1, INF));
    cout << KnapsackDfsWithMem(weights, values, mem, weights.size(), c) << endl;
    return 0;
}