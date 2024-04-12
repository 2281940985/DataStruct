#include<iostream>
#include<vector>

using namespace std;
//快速排序的核心操作是“哨兵划分”，其目标是：选择数组中的某个元素作为“基准数”，将所有小于基准数
//的元素移到其左侧，而大于基准数的元素移到其右侧
void swap(vector<int> &nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
//哨兵划分
int Partition(vector<int> &nums, int left, int right)
{
    int i = left;
    int j = right;
    while(i < j)//当左右指针相同时，循环结束
    {
        while (i < j && nums[j] >= nums[left])// 从右向左找首个小于基准数的元素
        {
            j--;//右边指针向右移
        }
        while(i < j && nums[i] <= nums[left])// 从左向右找首个大于基准数的元素
        {
            i++;//满足条件代表没找到，左边指针向右移
        }
        swap(nums,i,j);
        
    }
    swap(nums,i,left);//交换i和left索引处的元素。此时i位置元素肯定小于left，交换后刚好满足基准元素左侧都小于，右侧都大于基准元素
    return i ;
}
/* 选取三个候选元素的中位数 ,目的是为了找到数组中不大不小的数，这样可以提高快速排序的时间效率*/
int MedianThree(vector<int> &nums, int left, int mid, int right)
{
    if(nums[left] < nums[right] ^ nums[left] < nums[mid])
    {
        return left;
    }
    else if(nums[mid] < nums[right] ^ nums[mid] < nums[left])
    {
        return mid;
    }
    else
    {
        return right;
    }
}
int PartitionOptimize(vector<int> &nums, int left, int right)
{
    int med = MedianThree(nums, left, (left + right)/2, right);
    swap(nums, left, med);//交换中间大小的元素到最左边就可以调用之前写好的Paritition函数

    int i = left;
    int j = right;
    while(i < j)//当左右指针相同时，循环结束
    {
        while (i < j && nums[j] >= nums[left])// 从右向左找首个小于基准数的元素
        {
            j--;//右边指针向右移
        }
        while(i < j && nums[i] <= nums[left])// 从左向右找首个大于基准数的元素
        {
            i++;//满足条件代表没找到，左边指针向右移
        }
        swap(nums,i,j);
        
    }
    swap(nums,i,left);//交换i和left索引处的元素。此时i位置元素肯定小于left，交换后刚好满足基准元素左侧都小于，右侧都大于基准元素
    return i ;
}

void QuickSort(vector<int> &nums,int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int pivot = Partition(nums,left,right);
    QuickSort(nums,left,pivot-1);
    QuickSort(nums,pivot+1,right);
}
//尾递归优化，减少在极端情况下的占用的栈帧空间
void QuickSortOptimize(vector<int> &nums, int left, int right)
{
    while (left < right)
    {
        int pivot = PartitionOptimize(nums, left, right);
        if(pivot - left < right - pivot)//对两个子数组中较短的执行快速排序，占用的栈帧空间较少
        {
            QuickSortOptimize(nums, left, pivot-1);
            left = pivot + 1;//pivot左侧排序完成后，要开始排序pivot右侧的数组
        }
        else
        {
            QuickSortOptimize(nums, pivot + 1, right);
            right = pivot - 1;
        }
    }
    
}


int main()
{
    vector<int> nums = {13,33,44,64,82,1,3,343,5,67,8};
    vector<int> nums1 = {2,4,1,0,3,5};
    

    QuickSortOptimize(nums,0,nums.size()-1);
    for(auto &val : nums)
    {
        cout << val << "  ";
    }
    return 0;
}