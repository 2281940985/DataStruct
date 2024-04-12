#include<iostream>
#include<vector>
using namespace std;


void Merge(vector<int> &nums, int left, int mid, int right)
{
    // ������������Ϊ [left, mid], ������������Ϊ [mid+1, right]

    vector<int> tmp(right - left + 1);// ����һ����ʱ���� tmp �����ڴ�źϲ���Ľ��
    int i = left, j = mid + 1, k = 0;// ��ʼ����������������������ʼ����
    while(i <= mid && j <= right)// �����������鶼����Ԫ��ʱ�����бȽϲ�����С��Ԫ�ظ��Ƶ���ʱ������
    {
        if(nums[i] <= nums[j])
        {
            tmp[k++] = nums[i++];
        }
        else
        {
            tmp[k++] = nums[j++];
        }
    }//ÿ�ι鲢ʱ����������������һ����ȣ�����Ҫ��ʣ���Ԫ�ظ��Ƶ���ʱ�����У���Ϊʣ�������϶�ֻ��һ���Ѿ��鲢�õ������У��϶�������ʱ�����е�Ԫ�أ�����ֱ�Ӹ��Ƽ���
    while(i <= mid)
    {
        tmp[k++] = nums[i++];
    }
    while(j <= right)
    {
        tmp[k++] = nums[j++];
    }
    for(k = 0; k < tmp.size(); k++)
    {
        nums[left + k] = tmp[k];//ÿ�ι鲢�����Ԫ�ض��Ǵ����ҵ�(�ȹ鲢���������ڵ�������)�������������ֱ�Ӹ�ֵ��������һ������
    }
}
void MergeSort(vector<int> &nums, int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int mid = (left + right)/2;
    MergeSort(nums, left, mid);//�ݹ���������
    MergeSort(nums, mid + 1, right);//�ݹ���������
    Merge(nums, left, mid, right);
}

int main()
{
    vector<int> nums = {10,9,8,7,6,5,4,3,2,1};
    MergeSort(nums, 0, nums.size() - 1);
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}