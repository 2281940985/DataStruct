#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//获取元素num的第k位数字
int digit(int num, int exp)
{
    return (num / exp) % 10;
}
//计数排序(根据nums的第k位数字进行排序)
void CountingSortDigit(vector<int> &nums, int exp)
{
    vector<int> counter(10, 0);
    for(int i = 0; i < nums.size(); i++)
    {
        counter[digit(nums[i], exp)]++;
    }
    //利用前缀和的计数排序
    for(int i = 1; i < 10; i++)
    {
        counter[i] += counter[i - 1];//求前缀和
    }
    vector<int> res(nums.size(),0);
    for(int i = nums.size() - 1; i >= 0; i--)//倒序遍历,根据桶内统计结果，将各元素填入 res
    {
        int index = counter[digit(nums[i], exp)]-1;
        res[index] = nums[i];
        counter[digit(nums[i], exp)]--;
    }
    nums = res;
}
//基数排序
void RadixSort(vector<int> &nums)
{
    //获取最大元素，用于判断最大的位数
    int m = *max_element(nums.begin(), nums.end());
    for(int exp = 1; exp <= m; exp *= 10)// 对数组元素的第 k 位执行计数排序
    {
        // k = 1 -> exp = 1
        // k = 2 -> exp = 10
        CountingSortDigit(nums, exp);
    }
}
/*
为什么从最低位开始排序？
在连续的排序轮次中，后一轮排序会覆盖前一轮排序的结果。举例来说，如果第一轮排序结果
? < ? ，而第二轮排序结果 ? > ? ，那么第二轮的结果将取代第一轮的结果。由于数字的高
位优先级高于低位，因此应该先排序低位再排序高位。
*/

int main()
{
    vector<int> nums = {170657, 45645, 75645, 93240, 843202, 244234, 23467, 69789436};
    RadixSort(nums);
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}