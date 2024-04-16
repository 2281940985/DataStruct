#include<iostream>
#include<vector>

using namespace std;
//����һ���������飬���в������ظ�Ԫ�أ��������п��ܵ�����

void BackTrack(vector<int> &state, vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res)
{
    //��״̬���ȵ���Ԫ������ʱ��˵�����е�λ����¼�⣬���ص���һ��
    if(state.size() == choices.size())
    {
        res.push_back(state);
        return;
    }
    //��������ѡ��
    for(int i = 0; i < choices.size(); i++)
    {
        int choice = choices[i];
        //��֦���������ظ�Ԫ��
        if(selected[i] == false)
        {
            selected[i] = true;
            state.push_back(choice);

            //������һ��ѡ��
            BackTrack(state, choices, selected, res);

            //������ɣ����ˣ�������һ�ֵ�ѡ�񣬻ָ�����һ���״̬
            selected[i] = false;
            state.pop_back();//����һ��forѭ��������i����������������������ж�������Ҳ�᷵����һ�����ִ�л��˲���
            //�����������ж������󣬻Ὺʼ�µ�һ��forѭ������ʱ�ͻ��ɵ���˳���Ŀ�ģ�������state���123���132.
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