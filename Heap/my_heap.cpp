#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class MaxHeap
{
public:
    vector<int> maxheap;
    MaxHeap(){}
    MaxHeap(vector<int> vec) 
    {
        for(int i : vec)
        {
            Push(i);
        }
    }
    ~MaxHeap() {}
    int Left(int i)
    {
        return 2*i+1;
    }
    int Right(int i)
    {
        return 2*i + 2;
    }
    int Parent(int i)
    {
        return (i-1)/2;
    }
    //访问堆顶元素
    int Peek()
    {
        return maxheap[0];
    }
    //元素入堆
    void Push(int num)
    {
        maxheap.push_back(num);
        int index = maxheap.size() - 1;
        while(true)
        {
            if(Parent(index) >= 0 && num > maxheap[Parent(index)])
            {
                int tmp = maxheap[Parent(index)];
                maxheap[Parent(index)] = num;
                maxheap[index] = tmp;
                index = Parent(index);
            }
            else
            {
                break;
            }
        }
    }
    //元素出堆
    void Pop()
    {
        int tmp = maxheap[0];
        maxheap[0] = maxheap[maxheap.size() - 1];
        maxheap[maxheap.size() - 1] = tmp;
        maxheap.pop_back();
        int index = 0;
        int max = index;
        while (true)
        {
            
            if(Left(index) < maxheap.size() - 1 && maxheap[max] < maxheap[Left(index)])
            {
                max = Left(index);
            }
            if(Right(index) < maxheap.size() - 1 && maxheap[max] < maxheap[Right(index)])
            {
                max = Right(index);
            }
            if(max == index)
            {
                break;
            }
            swap(maxheap[index], maxheap[max]);
            index = max;

        }
        
    }
    //打印堆元素
    void PrintHeap()
    {
        for(auto i : maxheap)
        {
            cout << i << " ";
        }
        cout << endl;
    }

};

int main()
{
    MaxHeap MH;
    MH.Push(1);
    MH.Push(2);
    MH.Push(3);
    MH.Push(4);
    MH.Push(5);
    MH.Push(6);
    MH.Push(7);
    cout << MH.Peek() << endl;
    MH.Pop();
    MH.PrintHeap();

    MaxHeap MH2({2,3,4,5,6,7,8,9,-1,-4,-5,-6,100});
    MH2.Pop();
    MH2.PrintHeap();
    return 0;
}