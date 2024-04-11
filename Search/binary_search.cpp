#include<iostream>
#include<vector>

using namespace std;
int BinarySearch(vector<int> vec,int target)
{
    int i = 0;
    int j = vec.size() - 1;
    while (i <= j)
    {
        int m = i + (j - i)/2;
        if(vec[m] > target)
        {
            j = m - 1;
        }
        else if (vec[m] < target)
        {
            i = m + 1;
        }
        else 
        {
            return m;
        }
    }
    return -1;
}
//二分查找插入点（无重复元素）
int BinarySearchInsertionSimple(vector<int> &nums, int target)
{
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j)
    {
        int m = i + (j-i)/2;
        if(nums[m] > target)
        {
            j = m - 1;
        }
        else if(nums[m] < target)
        {
            i = m + 1;
        }
        else
        {
            return m;
        }
    }
    return i;//未找到target,返回i就是要插入的位置，因为此时i指向首个大于target的元素
}

//二分查找插入点（有重复元素）查找目标元素第一次出现的索引即最左边的索引
int BinarySearchInsertion(vector<int> &nums, int target)
{
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j)  
    {
        int m = i + (j-i)/2;
        if(nums[m] < target)
        {
            i = m + 1;
        }
        else if(nums[m] > target)
        {
            j = m - 1;
        }
        else
        {
            j = m - 1;
        }
    }
    return i;
}
//二分查找最左一个target
int BinarySearchLeftEdge(vector<int> nums, int target)
{
    int i = BinarySearchInsertion(nums, target);//这个函数执行的是查找元素第一次出现的位置，默认了数组一定会出现该元素，所以要对特殊情况进行讨论
    if(i == nums.size() || nums[i] != target)
    {
        return -1;
    }
    return i;
}
//二分查找最右一个target
int BinarySearchRightEdge(vector<int> nums, int target)
{
    int i = BinarySearchInsertion(nums, target + 1);
    int j = i - 1;
    if(j == -1 || nums[j] != target)//为什么这里判断和前面查找最左边target不一样？
    //因为这里j=i-1,i最大为nums.size(),减1后不在越界可以用nums[j] != target判断，而当i=0时，i并未越界，但是i-1越界了，所以要单独考虑
    {
        return -1;
    }
    return j;
}
int main()
{
    vector<int> vec = { 1,2,3,4,5,6,7,8,9,11,23,445,667};
    cout << BinarySearch(vec,9) << endl;
    
    vector<int> nums1 = {1,3,6,8,12,15,23,26,31,35};
    cout << BinarySearchInsertionSimple(nums1,6) << endl;

    vector<int> nums2 = {1,3,6,6,6,6,6,10,12,15};
    cout << BinarySearchInsertion(nums2, 6) << endl;

    cout << BinarySearchLeftEdge(nums2, 6) << endl;
    cout << BinarySearchRightEdge(nums2,6) << endl;
}