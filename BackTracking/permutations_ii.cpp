#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//输入一个整数数组，数组中可能包含重复元素，返回所有不重复的排列
void BackTrack(vector<int> &state, vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res)
{
    if(state.size() == choices.size())
    {
        res.push_back(state);
        return;
    }
    //遍历所有选择
    unordered_set<int> duplicated;//记录重复的元素，在同一轮选择中，不能选择两次相同的元素
    //一般在迭代递归函数中尽量不要创建新的数据结构，因为这样会导致大量的内存分配和释放，降低程序性能
    //但是这里创建了unordered_set<int> duplicated;是为了记录本轮选择中已经选择过的元素，例如本轮若选择了1，则在回溯到这一层中
    //不能再次选择1，因为这样会导致重复排列，并且每一层的选择都是独立的，因此需要记录每一层的选择情况，所以在递归函数内部创建了一个unordered_set<int> duplicated;

    for(int i = 0; i < choices.size(); i++)//for循环决定循环的轮次，i=几决定当前循环的是第几轮
    {   // 剪枝：不允许重复选择元素 且 不允许重复选择相等元素
        if(selected[i] == false && duplicated.find(choices[i]) == duplicated.end())
        {
            duplicated.emplace(choices[i]);//记录选择过的元素值
            selected[i] = true;
            state.push_back(choices[i]);
            //进行下一轮选择
            BackTrack(state, choices, selected, res);
            //回溯
            selected[i] = false;
            state.pop_back();
        }
    }
}
//全排列
vector<vector<int>> PermutationsII(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> state;
    vector<bool> selected(nums.size(), false);
    BackTrack(state, nums, selected, res);
    return res;
}

int main()
{
    vector<int> nums = {1,1, 2, 4};
    vector<vector<int>> res = PermutationsII(nums);
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