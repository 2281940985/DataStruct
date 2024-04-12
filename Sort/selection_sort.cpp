#include<iostream>
#include<vector>

using namespace std;
//选择排序，每轮从未排序区间选择最小的元素，将其放到已排序区间的末尾。
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