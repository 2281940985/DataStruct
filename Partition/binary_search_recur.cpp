#include <iostream>
#include <vector>

using namespace std;
//辅助二分查找的递归函数
int Dfs(vector<int> &nums, int target, int i, int j)
{
    if(i > j)
    {
        return -1;
    }
    int m = (i+j)/2;
    if(nums[m] < target)
    {
        return Dfs(nums, target, m+1, j);
    }
    else if(nums[m] > target)
    {
        return Dfs(nums, target, i, m-1);
    }
    else
    {
        return m;
    }
}
int BinarySearch(vector<int> &nums, int target)
{
    return Dfs(nums, target, 0, nums.size()-1);
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int target = 5;
    cout << BinarySearch(nums, target) << endl;
    return 0;
}