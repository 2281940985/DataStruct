#include<iostream>
#include<vector>

using namespace std;
//��δ��������ѡ��һ����׼Ԫ�أ�����Ԫ��������������������Ԫ����һ�Ƚϴ�С��������Ԫ�ز��뵽��ȷ��λ�á�

void InsertionSort(vector<int> &nums)
{
    for(int i = 1; i < nums.size(); ++i)
    {
        int base = nums[i];
        int j = i - 1;
        while (j >= 0 && base < nums[j])//ÿһ�ֶ�������Ѿ�����õ��������ұ�Ԫ�ؽ��бȽϣ���Ϊ���ұ�Ԫ�����
        //������Ԫ��С����ֱ�ӽ�Ԫ�����ƣ�������ұ߱Ƚϣ��Դ�����ֱ���Ƚϵ���baseС��Ԫ�أ���ʱӦ�ý�base�����ڸ�Ԫ�ص��Ҳ�
        {
            nums[j + 1] = nums[j];
            j --;//����ִ��ѭ���жϣ�����ѭ��ʱjΪ��һ����baseС��Ԫ����������Ԫ�ز���Ҫ���ƣ�baseҪ�����������ұ�
        }
        nums[j+1] = base;//ԭ����j+1��Ԫ���Ѿ�������
        
    }
}
int main()
{
    vector<int> nums = {13,33,44,64,82,1,3,343,5,67,8};
    InsertionSort(nums);
    for(auto &val : nums)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}