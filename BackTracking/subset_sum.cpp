#include<iostream>
#include<vector>

using namespace std;

void BackTrack(vector<int> &state, int target, int total, vector<int> &choices, vector<vector<int>> &res)
{
    if(total == target)//������������¼���������
    {
        res.push_back(state);
        return;
    }
    for(int i = 0; i < choices.size(); i++)//û�ж���ļ�֦��������ظ��Ľ��������(4,5)��(5,4)�ĺ;�Ϊ9
    {
        if(total + choices[i] > target)
        {
            continue;
        }
        state.push_back(choices[i]);
        BackTrack(state, target, total + choices[i], choices, res);

        //���ˣ��ָ���֮ǰ״̬
        state.pop_back();
    }
}
vector<vector<int>> SubsetSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    vector<int> state;
    BackTrack(state, target, 0, nums, res);
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> res = SubsetSum(nums, 5);
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