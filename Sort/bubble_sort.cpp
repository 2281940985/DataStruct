#include<iostream>
#include<vector>

using namespace std;

void BubbleSort(vector<int> &nums)
{
    
    for(int i = nums.size() - 1; i > 0; --i)
    {
        for(int j = 0; j < i ; ++j)
        {
            if(nums[j] > nums[j+1])
            {
                swap(nums[j], nums[j+1]);
            }
        }
    }
}
//如果某轮“冒泡”中没有执行任何交换操作，说明数组已经完成排序，可直接返回结果
//增加一个标志位 flag 来监测这种情况，一旦出现就立即返回。
//在引入 flag 优化后，最佳时间复杂度可达到 ?(?) 。
void BubbleSortWithFlag(vector<int> &nums)
{
    
    for(int i = nums.size() - 1; i > 0; --i)
    {
        bool flag = false;
        for(int j = 0; j < i ; ++j)
        {
            if(nums[j] > nums[j+1])
            {
                swap(nums[j], nums[j+1]);
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
    }
}

int main()
{
    vector<int> nums = {13,33,44,64,82,1,3,343,5,67,8};
    BubbleSort(nums);
    for(auto &val : nums)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}