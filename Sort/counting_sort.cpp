#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void CountingSort(vector<int> &nums)
{//找到数组中最大的元素，并创建一个大小为max+1的数组
    int max = nums[0];
    for(auto &num : nums)
    {
        max = max > num ? max : num;
    }
    //统计各数字出现的次数，将nums数组的元素映射成count数组的下标
    vector<int> count(max + 1, 0);
    for(auto &num : nums)
    {
        count[num]++;
    }

    //遍历 nums ，将各元素填入原数组 nums----好难,还有种方法遍历count
    int i = 0, j = 0;
    for(int i = 0; i < nums.size(); )//从nums[0]开始遍历到nums[end]结束
    {
        
        while(count[j] == 0)//说明没有要传入nums数组的元素，直接跳过判断count数组下一个元素是否不为0
        {
            j ++;
        }
        //结束循环后说明遇到了count[j] != 0, 将count[j]的下标j传入nums数组,且要传入count[j]个j
        for(int k = 0; k < count[j]; k++)//入count[j]个j
        {
            nums[i] = j;
            i++;//每传入一个nums[i]就要指向下一个
        }
        j++;//传入给nums[i]完成后，要继续沿后判读count[j]是否为0
        
    }
}
/*
{
    //遍历count的方法
    int i = 0;
    for(int num = 0; num < count.size(); num++)//nums代表count数组的下标，即待传入nums的元素
    {
        for(int j = 0; j < count[num]; j++, i++)//count[num]代表传入nums的元素的个数,为0的话，不会进行该轮for循环,若count[num]不为0，则传入nums的元素为num，每传入一个元素，i++,因为nums[i]之前的元素都已经排序好了
        { //j++是为了保证传入到nums数组的个数为count[num]
            nums[i] = num;
        }
    }
}
*/

int main()
{
    vector<int> nums = { 3, 2,2,2,4,4,4,5,6,9,9,9,9};
    CountingSort(nums);
    for(auto &num : nums)
    {
        cout << num << " ";
    }
    return 0;



}