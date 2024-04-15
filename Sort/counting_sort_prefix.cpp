#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
void CountingSortPrefix(vector<int> &nums)
{
    int m = nums[0];
    for(auto &val : nums)
    {
        m = max(m, val);
    }
    vector<int> counter(m+1, 0);
    //统计nums中各个数字出现的次数
    for(auto val : nums)
    {
        counter[val]++;
    }
    //计算前缀和
    for(int i = 0; i < m; i++)
    {
        counter[i+1] += counter[i];
    }
    //倒序遍历nums,将各个元素填入结果数组res
    vector<int> res(nums.size(), 0);
    for(int i = nums.size()-1; i >= 0; i--)
    {
        res[counter[nums[i]] - 1] = nums[i];//counter[nums[i]]-1是nums[i]在res中最后一次出现的索引
        //为社么-1是因为数组的索引从0开始，而counter中的元素是从1开始计数
        counter[nums[i]]--;
    }
    //将结果数组res赋值给nums
    nums = res;
}
int main()
{
    vector<int> nums = {10, 9, 8, 7, 4, 6, 7, 8, 9, 10,9,8,7,56,6,5,4,3,1,2,3,4,5,6,7,8,9,10};
    CountingSortPrefix(nums);
    for(auto val : nums)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}