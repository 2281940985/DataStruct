#include <iostream>
#include <vector>

using namespace std;
/*
����һ������ ? �׵�¥�ݣ���ÿ�������� 1 �׻��� 2 �ף������ж����ַ�����������¥����
*/
void BackTrack(vector<int> &choices, int n, int state, vector<int> &res)//���ݷ�
{
    if(state == n)
    {
        res[0]++;
        return;//���Ｔʹ����returnҲû��ϵ����Ϊ�����ִ�к���Ĵ��룬��ʱ����forѭ����ÿһ��ѭ�����������������������
    }
    for(auto &choice : choices)
    {
        if(state + choice > n)
        {
            continue;
        }
        BackTrack(choices, n, state + choice, res);//����Ҫ����Ļ��ݲ���������ִ����Ϻ���Զ����ݣ����ݵ���һ����Զ���ȥchoice
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