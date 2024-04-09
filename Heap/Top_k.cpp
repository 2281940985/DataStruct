#include<iostream>
#include<queue>
#include<vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> TopKHeap(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> Heap;
        for(int i = 0; i < k; ++i)
        {
            Heap.push(nums[i]);
        }
        for(int i = k; i < nums.size(); ++i)
        {
            if(nums[i] > Heap.top())
            {
                Heap.pop();
                Heap.push(nums[i]);
            }
        }
        return Heap;

    }
//��������д��main�������棬����ᱨ��
int main()
{
    vector<int> nums = { 1, 3, 4, 5, 64, -3, -5, 40, 100, 99, 34, 54, 43};
    priority_queue<int, vector<int>, greater<int>> Heap = TopKHeap(nums,4);
    while (!Heap.empty())
    {
        cout << Heap.top() << " ";
        Heap.pop();
    }
    
    return 0;
}