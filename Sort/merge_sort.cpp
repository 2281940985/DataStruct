#include<iostream>
#include<vector>
using namespace std;


void Merge(vector<int> &nums, int left, int mid, int right)
{
    // 左子数组区间为 [left, mid], 右子数组区间为 [mid+1, right]

    vector<int> tmp(right - left + 1);// 创建一个临时数组 tmp ，用于存放合并后的结果
    int i = left, j = mid + 1, k = 0;// 初始化左子数组和右子数组的起始索引
    while(i <= mid && j <= right)// 当左右子数组都还有元素时，进行比较并将较小的元素复制到临时数组中
    {
        if(nums[i] <= nums[j])
        {
            tmp[k++] = nums[i++];
        }
        else
        {
            tmp[k++] = nums[j++];
        }
    }//每次归并时，左右子树数量不一定相等，所以要将剩余的元素复制到临时数组中，因为剩余的数组肯定只在一个已经归并好的数组中，肯定大于临时数组中的元素，所以直接复制即可
    while(i <= mid)
    {
        tmp[k++] = nums[i++];
    }
    while(j <= right)
    {
        tmp[k++] = nums[j++];
    }
    for(k = 0; k < tmp.size(); k++)
    {
        nums[left + k] = tmp[k];//每次归并排序的元素都是从左到右的(先归并左子树，在到右子树)，所以这里可以直接赋值，方便下一次排序
    }
}
void MergeSort(vector<int> &nums, int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int mid = (left + right)/2;
    MergeSort(nums, left, mid);//递归左子数组
    MergeSort(nums, mid + 1, right);//递归右子数组
    Merge(nums, left, mid, right);
}

int main()
{
    vector<int> nums = {10,9,8,7,6,5,4,3,2,1};
    MergeSort(nums, 0, nums.size() - 1);
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}