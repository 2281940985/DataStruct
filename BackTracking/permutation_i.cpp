#include<iostream>
#include<vector>

using namespace std;
//输入一个整数数组，其中不包含重复元素，返回所有可能的排列

void BackTrack(vector<int> &state, vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res)
{
    //当状态长度等于元素数量时，说明排列到位，记录解，返回到上一层
    if(state.size() == choices.size())
    {
        res.push_back(state);
        return;
    }
    //遍历所有选择
    for(int i = 0; i < choices.size(); i++)
    {
        int choice = choices[i];
        //剪枝，不允许重复元素
        if(selected[i] == false)
        {
            selected[i] = true;
            state.push_back(choice);

            //进行下一轮选择
            BackTrack(state, choices, selected, res);

            //排列完成，回退，撤销这一轮的选择，恢复到上一层的状态
            selected[i] = false;
            state.pop_back();//当这一轮for循环结束后，i会自增，如果自增后不满足判断条件，也会返回上一层继续执行回退操作
            //当自增满足判断条件后，会开始新的一轮for循环，此时就会达成调换顺序的目的，解释了state会从123变成132.
        }
    }

}

vector<vector<int>> PermutationsI(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> state;
    vector<int> choices = nums;
    vector<bool> selected(choices.size(), false);
    BackTrack(state, choices, selected, res);
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3,};
    vector<vector<int>> res = PermutationsI(nums);
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