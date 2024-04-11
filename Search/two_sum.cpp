#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
/*
����һ���������� nums ��һ��Ŀ��Ԫ�� target �������������������͡�Ϊ target ������Ԫ
�أ����������ǵ�������������������һ���⼴�ɡ�
*/
vector<int> TwoSumHashTable(vector<int> nums, int target)
{
    unordered_map<int,int> hash_table;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(hash_table.find(target - nums[i]) != hash_table.end())
        {//����֮���Խ�����ֵ��Ϊvalue�����ϣ����Ϊ��unordered_map�Ĺ�ϣ���У�����valueֱ����[key]����,��Ҫ����key,�����Ҫͨ������������
            return {hash_table[target - nums[i]], i};//hash_table[target - nums[i]]���ص���value,target-nums[i]��key
        }
        hash_table.emplace(nums[i], i);//�ڹ�ϣ�������Ԫ�أ���һ����key���ڶ�����value
    }
}
vector<vector<int>> TwoSum(vector<int> nums, int target)//���ܱ����溯����ʵ�ã����Է���������������͵���target������
{
    unordered_map<int, int> hash_table;
    vector<vector<int>> ret;
    int i = nums.size();
    while (i)
    {
        --i;
        if(hash_table.find(target - nums[i]) != hash_table.end())
        {
            ret.push_back({hash_table[target - nums[i]],i});//��ŷ���Ҫ��Ĺ�ϣ���value������
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
