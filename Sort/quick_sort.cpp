#include<iostream>
#include<vector>

using namespace std;
//��������ĺ��Ĳ����ǡ��ڱ����֡�����Ŀ���ǣ�ѡ�������е�ĳ��Ԫ����Ϊ����׼������������С�ڻ�׼��
//��Ԫ���Ƶ�����࣬�����ڻ�׼����Ԫ���Ƶ����Ҳ�
void swap(vector<int> &nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
//�ڱ�����
int Partition(vector<int> &nums, int left, int right)
{
    int i = left;
    int j = right;
    while(i < j)//������ָ����ͬʱ��ѭ������
    {
        while (i < j && nums[j] >= nums[left])// �����������׸�С�ڻ�׼����Ԫ��
        {
            j--;//�ұ�ָ��������
        }
        while(i < j && nums[i] <= nums[left])// �����������׸����ڻ�׼����Ԫ��
        {
            i++;//������������û�ҵ������ָ��������
        }
        swap(nums,i,j);
        
    }
    swap(nums,i,left);//����i��left��������Ԫ�ء���ʱiλ��Ԫ�ؿ϶�С��left��������պ������׼Ԫ����඼С�ڣ��Ҳ඼���ڻ�׼Ԫ��
    return i ;
}
/* ѡȡ������ѡԪ�ص���λ�� ,Ŀ����Ϊ���ҵ������в���С����������������߿��������ʱ��Ч��*/
int MedianThree(vector<int> &nums, int left, int mid, int right)
{
    if(nums[left] < nums[right] ^ nums[left] < nums[mid])
    {
        return left;
    }
    else if(nums[mid] < nums[right] ^ nums[mid] < nums[left])
    {
        return mid;
    }
    else
    {
        return right;
    }
}
int PartitionOptimize(vector<int> &nums, int left, int right)
{
    int med = MedianThree(nums, left, (left + right)/2, right);
    swap(nums, left, med);//�����м��С��Ԫ�ص�����߾Ϳ��Ե���֮ǰд�õ�Paritition����

    int i = left;
    int j = right;
    while(i < j)//������ָ����ͬʱ��ѭ������
    {
        while (i < j && nums[j] >= nums[left])// �����������׸�С�ڻ�׼����Ԫ��
        {
            j--;//�ұ�ָ��������
        }
        while(i < j && nums[i] <= nums[left])// �����������׸����ڻ�׼����Ԫ��
        {
            i++;//������������û�ҵ������ָ��������
        }
        swap(nums,i,j);
        
    }
    swap(nums,i,left);//����i��left��������Ԫ�ء���ʱiλ��Ԫ�ؿ϶�С��left��������պ������׼Ԫ����඼С�ڣ��Ҳ඼���ڻ�׼Ԫ��
    return i ;
}

void QuickSort(vector<int> &nums,int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int pivot = Partition(nums,left,right);
    QuickSort(nums,left,pivot-1);
    QuickSort(nums,pivot+1,right);
}
//β�ݹ��Ż��������ڼ�������µ�ռ�õ�ջ֡�ռ�
void QuickSortOptimize(vector<int> &nums, int left, int right)
{
    while (left < right)
    {
        int pivot = PartitionOptimize(nums, left, right);
        if(pivot - left < right - pivot)//�������������н϶̵�ִ�п�������ռ�õ�ջ֡�ռ����
        {
            QuickSortOptimize(nums, left, pivot-1);
            left = pivot + 1;//pivot���������ɺ�Ҫ��ʼ����pivot�Ҳ������
        }
        else
        {
            QuickSortOptimize(nums, pivot + 1, right);
            right = pivot - 1;
        }
    }
    
}


int main()
{
    vector<int> nums = {13,33,44,64,82,1,3,343,5,67,8};
    vector<int> nums1 = {2,4,1,0,3,5};
    

    QuickSortOptimize(nums,0,nums.size()-1);
    for(auto &val : nums)
    {
        cout << val << "  ";
    }
    return 0;
}