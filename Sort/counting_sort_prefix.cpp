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
    //ͳ��nums�и������ֳ��ֵĴ���
    for(auto val : nums)
    {
        counter[val]++;
    }
    //����ǰ׺��
    for(int i = 0; i < m; i++)
    {
        counter[i+1] += counter[i];
    }
    //�������nums,������Ԫ������������res
    vector<int> res(nums.size(), 0);
    for(int i = nums.size()-1; i >= 0; i--)
    {
        res[counter[nums[i]] - 1] = nums[i];//counter[nums[i]]-1��nums[i]��res�����һ�γ��ֵ�����
        //Ϊ��ô-1����Ϊ�����������0��ʼ����counter�е�Ԫ���Ǵ�1��ʼ����
        counter[nums[i]]--;
    }
    //���������res��ֵ��nums
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