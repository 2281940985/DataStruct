#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
给定一个正整数 ? ，将其切分为至少两个正整数的和，求切分后所有整数的乘积最大是多少，
*/
int MaxProductCutting(int n)
{
    if(n <= 3)
    {
        return 1 * (n-1);
    }
    int a = n/3;
    int b = n%3;
    if(b == 1)
    {
        return pow(3,a-1) * 2 * 2;//当余数为 1 时，由于 2 × 2 > 1 × 3 ，因此应将最后一个 3 替换为 2 。
    }
    else if(b == 0)
    {
        return pow(3,a);
    }
    else 
    {
        return pow(3,a) * b;
    }
}
/*贪心策略:
1. 输入整数 ? ，从其不断地切分出因子 3 ，直至余数为 0、1、2 。
2. 当余数为 0 时，代表 ? 是 3 的倍数，因此不做任何处理。
3. 当余数为 2 时，不继续划分，保留。
4. 当余数为 1 时，由于 2 × 2 > 1 × 3 ，因此应将最后一个 3 替换为 2 。
*/
int main()
{
    cout << MaxProductCutting(10) << endl;
    return 0;
}

