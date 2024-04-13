#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void BucketSort(vector<float> &nums)
{   // ��ʼ�� k = n/2 ��Ͱ��Ԥ����ÿ��Ͱ���� 2 ��Ԫ��
    int k = nums.size()/2;
    vector<vector<float>> buckets(k);
    for(auto &num : nums)
    {
        buckets[num * k].push_back(num);// �������ݷ�ΧΪ [0, 1)��ʹ�� num * k ӳ�䵽������Χ [0, k-1]
    }
    for(auto &bucket : buckets)//Ҫ��ԭ��������޸ģ�һ��Ҫ�ǵô�������
    {
        sort(bucket.begin(), bucket.end(),less<float>());//��ÿ��Ͱ��������Ͱ��Ͱ֮���Ѿ��������
    }
    int i = 0;//����д��ѭ�����棬��Ϊnums[i]֮ǰ��Ԫ���Ѿ���ֵ���ˣ��������޸�
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