#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
/*
给定一个整数数组 nums 和一个目标元素 target ，请在数组中搜索“和”为 target 的两个元
素，并返回它们的数组索引。返回任意一个解即可。
*/
vector<int> TwoSumHashTable(vector<int> nums, int target)
{
    unordered_map<int,int> hash_table;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(hash_table.find(target - nums[i]) != hash_table.end())
        {//这里之所以将索引值作为value传入哈希表，因为在unordered_map的哈希表中，查找value直接用[key]即可,若要查找key,则必须要通过迭代器查找
            return {hash_table[target - nums[i]], i};//hash_table[target - nums[i]]返回的是value,target-nums[i]是key
        }
        hash_table.emplace(nums[i], i);//在哈希表中添加元素，第一个是key，第二个是value
    }
}
vector<vector<int>> TwoSum(vector<int> nums, int target)//功能比上面函数更实用，可以返回数组中所有求和等于target的数组
{
    unordered_map<int, int> hash_table;
    vector<vector<int>> ret;
    int i = nums.size();
    while (i)
    {
        --i;
        if(hash_table.find(target - nums[i]) != hash_table.end())
        {
            ret.push_back({hash_table[target - nums[i]],i});//存放符合要求的哈希表的value即索引
        }
        hash_table.emplace(nums[i],i);
        
    }
    return ret;
    
}
int main()
{
    vector<int> nums = { 1,2,3,4,5,6,7,8,9};
    vector<int> ret = TwoSumHashTable(nums,10);
    for(auto &val : ret)
    {
        cout << val << "  ";
    }
    cout << endl;
    vector<vector<int>> ret1 = TwoSum(nums, 10);
    for(auto &ret : ret1)
    {
        cout << ret[0] << "  " << ret[1] << endl;
    }
}
