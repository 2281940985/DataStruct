#include<iostream>
#include<vector>

using namespace std;
//在未排序区间选择一个基准元素，将该元素与其左侧已排序区间的元素逐一比较大小，并将该元素插入到正确的位置。

void InsertionSort(vector<int> &nums)
{
    for(int i = 1; i < nums.size(); ++i)
    {
        int base = nums[i];
        int j = i - 1;
        while (j >= 0 && base < nums[j])//每一轮都和左侧已经排序好的区间最右边元素进行比较，因为最右边元素最大，
        //比最大的元素小，就直接将元素右移，在与次右边比较，以此类推直到比较到比base小的元素，此时应该将base插入在该元素的右侧
        {
            nums[j + 1] = nums[j];
            j --;//重新执行循环判断，跳出循环时j为第一个比base小的元素索引，该元素不需要右移，base要插入在它的右边
        }
        nums[j+1] = base;//原来的j+1的元素已经右移了
        
    }
}
int main()
{
    vector<int> nums = {13,33,44,64,82,1,3,343,5,67,8};
    InsertionSort(nums);
    for(auto &val : nums)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}