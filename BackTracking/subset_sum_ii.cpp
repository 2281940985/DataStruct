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
    //�������е�ѡ��
    // ��֦������ start ��ʼ���������������ظ��Ӽ�
    for(int i = start; i < choices.size(); i++)
    {   // ��֦һ�����Ӽ��ͳ��� target ����ֱ�ӽ���ѭ��
        if(target - choices[i] < 0)
        {
            break;// ������Ϊ���������򣬺��Ԫ�ظ����Ӽ���һ������ target,������break
        }
        state.push_back(choices[i]);
        BackTrack(state, target - choices[i], choices, i, res);//��һ�ֵı���ֻ�ܴ�choices[i]��ʼ����Ϊ��i֮ǰ��Ԫ�ض��Ѿ���������
        //��Ϊi = startʱ������������࣬�ڶ����������������֦һ��Ԫ�أ����Ե�i++�󣬴�choices����ĵڶ���Ԫ�ؿ�ʼ��������ʱ���迼����start����Ľ����
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