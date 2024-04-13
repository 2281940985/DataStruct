#include<iostream>
#include<vector>

using namespace std;

void SiftDown(vector<int> &nums, int n, int start)
{   //堆的长度为n,从节点start开始，从顶到底大堆化
    while(true)
    {
        //判断父节点和两个子节点的大小关系
        int left = 2 * start + 1;
        int right = 2 * start + 2;
        int max = start;
        if(left < n && nums[left] > nums[max])
        {
            max = left;
        }//不能写成else if因为即使执行了上一个if语句，这一句也要继续执行才能找到最大节点
        if(right < n && nums[right] > nums[max])
        {
            max = right;
        }
        if(max == start)//若节点max最大或索引left,right越界，则无须继续堆化，跳出,完成了对这一子树的大堆化操作，整个数组的堆化并未完成
        {
            break;//还要用for循环来完成对以这个子树父节点为子节点的子树的堆化，以此类推才能完成整个数组的大堆化
        }
        swap(nums[start], nums[max]);//将子树的最大值作为父节点
        start = max;//循环向下继续堆化，相当于把以发生交换的节点为父节点，对该新的子树进行大堆化
    }
}
//堆排序
void HeapSort(vector<int> &nums)
{
    for(int i = nums.size()/2 - 1; i >= 0; i--)
    {
        SiftDown(nums, nums.size(), i);//从最后一个非叶子节点开始，对整个数组进行大堆化,可以理解为先对最底层父节点进行大堆化，再对其父节点进行大堆化，以此类推，直到对整个数组进行大堆化
    }
    for(int i = nums.size() - 1; i > 0; i--)
    {
        swap(nums[0], nums[i]);//交换最大的元素和最后一个元素，此时数组中最后一个元素完成排序
        SiftDown(nums, i, 0);//数组长度减1，对剩余的元素进行大堆化，在将未排序的数组最后的元素和第一个元素交换，以此类推，直到数组中所有元素都完成排序
    }
}

//简而言之堆化排序最主要两个步骤：堆化操作是按照从顶至底进行堆化，当堆化交换操作发生时，必须要对发生交换后的元素继续堆化，直到子树不需要堆化或者跳出了数组区间（即叶子节点）；
//从数组中最后一个非叶子点开始堆化，先堆化最底层的子树，在堆化它的上一层子树，以此类推，直到堆化整个数组；
//堆排序操作是将未排序的数组最后的元素和第一个元素交换，然后在执行堆化操作以此类推，直到数组中所有元素都完成排序



int main()
{
    vector<int> nums = {9,8,7,6,5,4,3,2,1,122,432,2343,5,65,767,87};
    HeapSort(nums);
    for(auto &val : nums)
    {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}