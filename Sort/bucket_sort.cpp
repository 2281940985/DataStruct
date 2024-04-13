#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void BucketSort(vector<float> &nums)
{   // 初始化 k = n/2 个桶，预期向每个桶分配 2 个元素
    int k = nums.size()/2;
    vector<vector<float>> buckets(k);
    for(auto &num : nums)
    {
        buckets[num * k].push_back(num);// 输入数据范围为 [0, 1)，使用 num * k 映射到索引范围 [0, k-1]
    }
    for(auto &bucket : buckets)//要对原数组进行修改，一定要记得传入引用
    {
        sort(bucket.begin(), bucket.end(),less<float>());//对每个桶进行排序，桶与桶之间已经排序完成
    }
    int i = 0;//不能写在循环里面，因为nums[i]之前的元素已经赋值过了，不能在修改
    for(auto &bucket : buckets)
    {
        for(auto &num : bucket)
        {
            nums[i++] = num;
        }
    }
}
int main()
{
    vector<float> nums = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    BucketSort(nums);
    for(auto num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}