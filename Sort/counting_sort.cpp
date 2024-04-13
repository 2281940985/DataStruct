#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void CountingSort(vector<int> &nums)
{//�ҵ�����������Ԫ�أ�������һ����СΪmax+1������
    int max = nums[0];
    for(auto &num : nums)
    {
        max = max > num ? max : num;
    }
    //ͳ�Ƹ����ֳ��ֵĴ�������nums�����Ԫ��ӳ���count������±�
    vector<int> count(max + 1, 0);
    for(auto &num : nums)
    {
        count[num]++;
    }

    //���� nums ������Ԫ������ԭ���� nums----����,�����ַ�������count
    int i = 0, j = 0;
    for(int i = 0; i < nums.size(); )//��nums[0]��ʼ������nums[end]����
    {
        
        while(count[j] == 0)//˵��û��Ҫ����nums�����Ԫ�أ�ֱ�������ж�count������һ��Ԫ���Ƿ�Ϊ0
        {
            j ++;
        }
        //����ѭ����˵��������count[j] != 0, ��count[j]���±�j����nums����,��Ҫ����count[j]��j
        for(int k = 0; k < count[j]; k++)//��count[j]��j
        {
            nums[i] = j;
            i++;//ÿ����һ��nums[i]��Ҫָ����һ��
        }
        j++;//�����nums[i]��ɺ�Ҫ�����غ��ж�count[j]�Ƿ�Ϊ0
        
    }
}
/*
{
    //����count�ķ���
    int i = 0;
    for(int num = 0; num < count.size(); num++)//nums����count������±꣬��������nums��Ԫ��
    {
        for(int j = 0; j < count[num]; j++, i++)//count[num]������nums��Ԫ�صĸ���,Ϊ0�Ļ���������и���forѭ��,��count[num]��Ϊ0������nums��Ԫ��Ϊnum��ÿ����һ��Ԫ�أ�i++,��Ϊnums[i]֮ǰ��Ԫ�ض��Ѿ��������
        { //j++��Ϊ�˱�֤���뵽nums����ĸ���Ϊcount[num]
            nums[i] = num;
        }
    }
}
*/

int main()
{
    vector<int> nums = { 3, 2,2,2,4,4,4,5,6,9,9,9,9};
    CountingSort(nums);
    for(auto &num : nums)
    {
        cout << num << " ";
    }
    return 0;



}