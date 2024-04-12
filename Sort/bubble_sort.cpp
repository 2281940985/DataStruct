#include<iostream>
#include<vector>

using namespace std;

void BubbleSort(vector<int> &nums)
{
    
    for(int i = nums.size() - 1; i > 0; --i)
    {
        for(int j = 0; j < i ; ++j)
        {
            if(nums[j] > nums[j+1])
            {
                swap(nums[j], nums[j+1]);
            }
        }
    }
}
//���ĳ�֡�ð�ݡ���û��ִ���κν���������˵�������Ѿ�������򣬿�ֱ�ӷ��ؽ��
//����һ����־λ flag ��������������һ�����־��������ء�
//������ flag �Ż������ʱ�临�Ӷȿɴﵽ ?(?) ��
void BubbleSortWithFlag(vector<int> &nums)
{
    
    for(int i = nums.size() - 1; i > 0; --i)
    {
        bool flag = false;
        for(int j = 0; j < i ; ++j)
        {
            if(nums[j] > nums[j+1])
            {
                swap(nums[j], nums[j+1]);
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
    }
}

int main()
{
    vector<int> nums = {13,33,44,64,82,1,3,343,5,67,8};
    BubbleSort(nums);
    for(auto &val : nums)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}