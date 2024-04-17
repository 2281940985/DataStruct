#include<iostream>
#include<vector>

using namespace std;
/*
为了提升算法效率，我们希望所有的重叠子问题都只被计算一次。为此，我们声明一个数组 mem 来记录每个
子问题的解，并在搜索过程中将重叠子问题剪枝。
1. 当首次计算 ??[?] 时，我们将其记录至 mem[i] ，以便之后使用。
2. 当再次需要计算 ??[?] 时，我们便可直接从 mem[i] 中获取结果，从而避免重复计算该子问题。
*/
int Dfs(int i, vector<int> &mem)
{
    if(i == 1 || i == 2)
    {
        return i;
    }
    if(mem[i] != 0)
    {
        return mem[i];//这段要写在 int count = Dfs(i-1,mem) + Dfs(i-2,mem)之前，因为当mem[i]存在时，不需要再次分解计算，
                     //直接返回即可，并且返回到上一层int count = Dfs(i-1,mem) + Dfs(i-2,mem)中
    }
    int count = Dfs(i-1,mem) + Dfs(i-2,mem);
    mem[i] = count;//记录当前子问题的解，因为mem是一个数组，记录为i的子问题的解，所以不需要返回
    return count;//需要返回count到上一层，继续求解上一层的count
}

int ClimbingStairs(int n)
{
    vector<int> mem(n+1, 0);
    return Dfs(n,mem);
}//经过记忆化处理后，所有重叠子问题都只需计算一次，时间复杂度优化至 ?(?) 

int main()
{
    int n = 4;
    cout << ClimbingStairs(n) << endl;
    return 0;
}