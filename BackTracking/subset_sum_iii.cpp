#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
给定一个正整数数组 nums 和一个目标正整数 target ，请找出所有可能的组合，使得组合中的
元素和等于 target 。给定数组可能包含重复元素，每个元素只可被选择一次。请以列表形式
返回这些组合，列表中不应包含重复组合。
*/


void BackTrack(vector<int> &state, vector<int> &choices, int target, int start, vector<vector<int>> &res)
{
    if(target == 0)
    {
        res.push_back(state);
        return;
    }
    // 遍历所有选择
    // 剪枝二：从 start 开始遍历，避免生成重复子集
    for(int i = start; i < choices.size(); i++)
    {
        // 剪枝一：若子集和超过 target ，则直接结束循环
        if(target - choices[i] < 0)
        {
            break;//choices是排序好的数组，所以target-choices[i] < 0，i后面的也一定小于0
        }
        // 剪枝三：从 start 开始遍历，并比较相邻元素是否重复，避免重复选择同一元素
        if(i > start && choices[i] == choices[i-1])
        {
            continue;
        }
        state.push_back(choices[i]);
        BackTrack(state, choices, target - choices[i], i+1, res);//传入i+1，是因为每个元素只能被选择1次,当前轮次选择i后，下一轮只能从i+1开始选择
        state.pop_back();
    }
}
vector<vector<int>> SubsetSumIII(vector<int> &nums, int target)
{
    vector<int> state;
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    BackTrack(state, nums, target, 0, res);
    return res;
}
int main()
{
    vector<int> nums = {1,2,3,4,4,3,5,6,6};
    int target = 10;
    vector<vector<int>> res = SubsetSumIII(nums, target);
    for(auto &v : res)
    {
        for(auto &i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}