#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//����һ���������飬�����п��ܰ����ظ�Ԫ�أ��������в��ظ�������
void BackTrack(vector<int> &state, vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res)
{
    if(state.size() == choices.size())
    {
        res.push_back(state);
        return;
    }
    //��������ѡ��
    unordered_set<int> duplicated;//��¼�ظ���Ԫ�أ���ͬһ��ѡ���У�����ѡ��������ͬ��Ԫ��
    //һ���ڵ����ݹ麯���о�����Ҫ�����µ����ݽṹ����Ϊ�����ᵼ�´������ڴ������ͷţ����ͳ�������
    //�������ﴴ����unordered_set<int> duplicated;��Ϊ�˼�¼����ѡ�����Ѿ�ѡ�����Ԫ�أ����籾����ѡ����1�����ڻ��ݵ���һ����
    //�����ٴ�ѡ��1����Ϊ�����ᵼ���ظ����У�����ÿһ���ѡ���Ƕ����ģ������Ҫ��¼ÿһ���ѡ������������ڵݹ麯���ڲ�������һ��unordered_set<int> duplicated;

    for(int i = 0; i < choices.size(); i++)//forѭ������ѭ�����ִΣ�i=��������ǰѭ�����ǵڼ���
    {   // ��֦���������ظ�ѡ��Ԫ�� �� �������ظ�ѡ�����Ԫ��
        if(selected[i] == false && duplicated.find(choices[i]) == duplicated.end())
        {
            duplicated.emplace(choices[i]);//��¼ѡ�����Ԫ��ֵ
            selected[i] = true;
            state.push_back(choices[i]);
            //������һ��ѡ��
            BackTrack(state, choices, selected, res);
            //����
            selected[i] = false;
            state.pop_back();
        }
    }
}
//ȫ����
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