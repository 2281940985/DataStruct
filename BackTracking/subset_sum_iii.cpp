#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
����һ������������ nums ��һ��Ŀ�������� target �����ҳ����п��ܵ���ϣ�ʹ������е�
Ԫ�غ͵��� target ������������ܰ����ظ�Ԫ�أ�ÿ��Ԫ��ֻ�ɱ�ѡ��һ�Ρ������б���ʽ
������Щ��ϣ��б��в�Ӧ�����ظ���ϡ�
*/


void BackTrack(vector<int> &state, vector<int> &choices, int target, int start, vector<vector<int>> &res)
{
    if(target == 0)
    {
        res.push_back(state);
        return;
    }
    // ��������ѡ��
    // ��֦������ start ��ʼ���������������ظ��Ӽ�
    for(int i = start; i < choices.size(); i++)
    {
        // ��֦һ�����Ӽ��ͳ��� target ����ֱ�ӽ���ѭ��
        if(target - choices[i] < 0)
        {
            break;//choices������õ����飬����target-choices[i] < 0��i�����Ҳһ��С��0
        }
        // ��֦������ start ��ʼ���������Ƚ�����Ԫ���Ƿ��ظ��������ظ�ѡ��ͬһԪ��
        if(i > start && choices[i] == choices[i-1])
        {
            continue;
        }
        state.push_back(choices[i]);
        BackTrack(state, choices, target - choices[i], i+1, res);//����i+1������Ϊÿ��Ԫ��ֻ�ܱ�ѡ��1��,��ǰ�ִ�ѡ��i����һ��ֻ�ܴ�i+1��ʼѡ��
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