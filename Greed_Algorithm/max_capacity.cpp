#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
输入一个数组 ?? ，其中的每个元素代表一个垂直隔板的高度。数组中的任意两个隔板，以及
它们之间的空间可以组成一个容器。
容器的容量等于高度和宽度的乘积（面积），其中高度由较短的隔板决定，宽度是两个隔板的
数组索引之差。
请在数组中选择两个隔板，使得组成的容器的容量最大，返回最大容量。
*/
int MaxCapacity(vector<int> &heights)
{
    int res = 0;
    int left = 0;
    int right = heights.size() - 1;
    while(left < right)//代码循环最多 ? 轮，因此时间复杂度为 ?(?) 。
    {
        int temp = min(heights[left], heights[right]) * (right - left);
        if(heights[left] < heights[right])
        {
            left++;//我们只有向内收缩短板 ? ，才有可能使容量变大。因为虽然宽度一定变小，但高度可能会变大（移
                    //动后的短板 ? 可能会变长）
        }
        else
        {
            right--;//之所以贪心比穷举更快，是因为每轮的贪心选择都会“跳过”一些状态
        }
        res = max(res, temp);
    }
    return res;
}
int main()
{
    vector<int> heights = {3, 8, 5, 2, 7, 7,3,4};
    cout << MaxCapacity(heights) << endl;
    return 0;
}