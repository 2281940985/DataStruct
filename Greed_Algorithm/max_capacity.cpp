#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
����һ������ ?? �����е�ÿ��Ԫ�ش���һ����ֱ����ĸ߶ȡ������е������������壬�Լ�
����֮��Ŀռ�������һ��������
�������������ڸ߶ȺͿ�ȵĳ˻�������������и߶��ɽ϶̵ĸ����������������������
��������֮�
����������ѡ���������壬ʹ����ɵ�������������󣬷������������
*/
int MaxCapacity(vector<int> &heights)
{
    int res = 0;
    int left = 0;
    int right = heights.size() - 1;
    while(left < right)//����ѭ����� ? �֣����ʱ�临�Ӷ�Ϊ ?(?) ��
    {
        int temp = min(heights[left], heights[right]) * (right - left);
        if(heights[left] < heights[right])
        {
            left++;//����ֻ�����������̰� ? �����п���ʹ���������Ϊ��Ȼ���һ����С�����߶ȿ��ܻ�����
                    //����Ķ̰� ? ���ܻ�䳤��
        }
        else
        {
            right--;//֮����̰�ı���ٸ��죬����Ϊÿ�ֵ�̰��ѡ�񶼻ᡰ������һЩ״̬
        }
        res = max(res, temp);
    }
    return res;
}
int main()
{
    vector<int> heights = {3, 8, 5, 2, 7, 7,3,4};
    cout << MaxCapacity(heights) << endl;
    return 0;
}