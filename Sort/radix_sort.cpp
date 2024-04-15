#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//��ȡԪ��num�ĵ�kλ����
int digit(int num, int exp)
{
    return (num / exp) % 10;
}
//��������(����nums�ĵ�kλ���ֽ�������)
void CountingSortDigit(vector<int> &nums, int exp)
{
    vector<int> counter(10, 0);
    for(int i = 0; i < nums.size(); i++)
    {
        counter[digit(nums[i], exp)]++;
    }
    //����ǰ׺�͵ļ�������
    for(int i = 1; i < 10; i++)
    {
        counter[i] += counter[i - 1];//��ǰ׺��
    }
    vector<int> res(nums.size(),0);
    for(int i = nums.size() - 1; i >= 0; i--)//�������,����Ͱ��ͳ�ƽ��������Ԫ������ res
    {
        int index = counter[digit(nums[i], exp)]-1;
        res[index] = nums[i];
        counter[digit(nums[i], exp)]--;
    }
    nums = res;
}
//��������
void RadixSort(vector<int> &nums)
{
    //��ȡ���Ԫ�أ������ж�����λ��
    int m = *max_element(nums.begin(), nums.end());
    for(int exp = 1; exp <= m; exp *= 10)// ������Ԫ�صĵ� k λִ�м�������
    {
        // k = 1 -> exp = 1
        // k = 2 -> exp = 10
        CountingSortDigit(nums, exp);
    }
}
/*
Ϊʲô�����λ��ʼ����
�������������ִ��У���һ������Ḳ��ǰһ������Ľ����������˵�������һ��������
? < ? �����ڶ��������� ? > ? ����ô�ڶ��ֵĽ����ȡ����һ�ֵĽ�����������ֵĸ�
λ���ȼ����ڵ�λ�����Ӧ���������λ�������λ��
*/

int main()
{
    vector<int> nums = {170657, 45645, 75645, 93240, 843202, 244234, 23467, 69789436};
    RadixSort(nums);
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}