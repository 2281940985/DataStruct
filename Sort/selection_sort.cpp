#include<iostream>
#include<vector>

using namespace std;
//ѡ������ÿ�ִ�δ��������ѡ����С��Ԫ�أ�����ŵ������������ĩβ��
void SelectionSort(vector<int> &nums)
{
    for(int i = 0; i < nums.size(); ++i)
    {
        int k = i;
        for(int j = i+1; j < nums.size(); ++j)
        {
            if(nums[i] > nums[j])
            {
                k = j;
            }

        }
        swap(nums[i],nums[k]);
    }
}