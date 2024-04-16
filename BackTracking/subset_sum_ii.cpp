#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void BackTrack(vector<int> &state, int target, vector<int> &choices, int start, vector<vector<int>> &res)
{
    if(target == 0)
    {
        res.push_back(state);
    }
    //遍历所有的选择
    // 剪枝二：从 start 开始遍历，避免生成重复子集
    for(int i = start; i < choices.size(); i++)
    {   // 剪枝一：若子集和超过 target ，则直接结束循环
        if(target - choices[i] < 0)
        {
            break;// 这是因为数组已排序，后边元素更大，子集和一定超过 target,所以用break
        }
        state.push_back(choices[i]);
        BackTrack(state, target - choices[i], choices, i, res);//下一轮的遍历只能从choices[i]开始，因为在i之前的元素都已经遍历过了
        //因为i = start时遍历的种类最多，第二层会遍历所有满足剪枝一的元素，所以当i++后，从choices数组的第二个元素开始遍历，此时无需考虑与start搭配的结果了
        state.pop_back();
    }
}
vector<vector<int>> SubsetSumII(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    vector<int> state;
    sort(nums.begin(), nums.end());
    BackTrack(state, target, nums, 0, res);
    return res;
}
int main()
{
    vector<int> nums = {3,4,5,6};
    vector<vector<int>> res = SubsetSumII(nums, 9);
    for(auto &val : res)
    {
        for(auto &v : val)
        {
            cout << v << " ";
        }
        cout << endl;
    }
}