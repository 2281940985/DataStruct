#include<iostream>
#include<vector>

using namespace std;
int BinarySearch(vector<int> vec,int target)
{
    int i = 0;
    int j = vec.size() - 1;
    while (i <= j)
    {
        int m = i + (j - i)/2;
        if(vec[m] > target)
        {
            j = m - 1;
        }
        else if (vec[m] < target)
        {
            i = m + 1;
        }
        else 
        {
            return m;
        }
    }
    return -1;
}
//���ֲ��Ҳ���㣨���ظ�Ԫ�أ�
int BinarySearchInsertionSimple(vector<int> &nums, int target)
{
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j)
    {
        int m = i + (j-i)/2;
        if(nums[m] > target)
        {
            j = m - 1;
        }
        else if(nums[m] < target)
        {
            i = m + 1;
        }
        else
        {
            return m;
        }
    }
    return i;//δ�ҵ�target,����i����Ҫ�����λ�ã���Ϊ��ʱiָ���׸�����target��Ԫ��
}

//���ֲ��Ҳ���㣨���ظ�Ԫ�أ�����Ŀ��Ԫ�ص�һ�γ��ֵ�����������ߵ�����
int BinarySearchInsertion(vector<int> &nums, int target)
{
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j)  
    {
        int m = i + (j-i)/2;
        if(nums[m] < target)
        {
            i = m + 1;
        }
        else if(nums[m] > target)
        {
            j = m - 1;
        }
        else
        {
            j = m - 1;
        }
    }
    return i;
}
//���ֲ�������һ��target
int BinarySearchLeftEdge(vector<int> nums, int target)
{
    int i = BinarySearchInsertion(nums, target);//�������ִ�е��ǲ���Ԫ�ص�һ�γ��ֵ�λ�ã�Ĭ��������һ������ָ�Ԫ�أ�����Ҫ�����������������
    if(i == nums.size() || nums[i] != target)
    {
        return -1;
    }
    return i;
}
//���ֲ�������һ��target
int BinarySearchRightEdge(vector<int> nums, int target)
{
    int i = BinarySearchInsertion(nums, target + 1);
    int j = i - 1;
    if(j == -1 || nums[j] != target)//Ϊʲô�����жϺ�ǰ����������target��һ����
    //��Ϊ����j=i-1,i���Ϊnums.size(),��1����Խ�������nums[j] != target�жϣ�����i=0ʱ��i��δԽ�磬����i-1Խ���ˣ�����Ҫ��������
    {
        return -1;
    }
    return j;
}
int main()
{
    vector<int> vec = { 1,2,3,4,5,6,7,8,9,11,23,445,667};
    cout << BinarySearch(vec,9) << endl;
    
    vector<int> nums1 = {1,3,6,8,12,15,23,26,31,35};
    cout << BinarySearchInsertionSimple(nums1,6) << endl;

    vector<int> nums2 = {1,3,6,6,6,6,6,10,12,15};
    cout << BinarySearchInsertion(nums2, 6) << endl;

    cout << BinarySearchLeftEdge(nums2, 6) << endl;
    cout << BinarySearchRightEdge(nums2,6) << endl;
}