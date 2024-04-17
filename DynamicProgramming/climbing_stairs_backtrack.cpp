#include <iostream>
#include <vector>

using namespace std;
/*
给定一个共有 ? 阶的楼梯，你每步可以上 1 阶或者 2 阶，请问有多少种方案可以爬到楼顶？
*/
void BackTrack(vector<int> &choices, int n, int state, vector<int> &res)//回溯法
{
    if(state == n)
    {
        res[0]++;
        return;//这里即使不加return也没关系，因为会继续执行后面的代码，此时进入for循环，每一轮循环都不满足继续迭代的条件
    }
    for(auto &choice : choices)
    {
        if(state + choice > n)
        {
            continue;
        }
        BackTrack(choices, n, state + choice, res);//不需要额外的回溯操作，代码执行完毕后会自动回溯，回溯到上一层会自动减去choice
    }
}
int ClimbingStairs(int n)
{
    vector<int> choices = {1,2};
    vector<int> res(1,0);
    BackTrack(choices, n, 0, res);
    return res[0];
}
int main()
{
    cout << ClimbingStairs(4) << endl;
    return 0;
}