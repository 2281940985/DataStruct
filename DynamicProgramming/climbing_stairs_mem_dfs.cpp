#include<iostream>
#include<vector>

using namespace std;
/*
Ϊ�������㷨Ч�ʣ�����ϣ�����е��ص������ⶼֻ������һ�Ρ�Ϊ�ˣ���������һ������ mem ����¼ÿ��
������Ľ⣬�������������н��ص��������֦��
1. ���״μ��� ??[?] ʱ�����ǽ����¼�� mem[i] ���Ա�֮��ʹ�á�
2. ���ٴ���Ҫ���� ??[?] ʱ�����Ǳ��ֱ�Ӵ� mem[i] �л�ȡ������Ӷ������ظ�����������⡣
*/
int Dfs(int i, vector<int> &mem)
{
    if(i == 1 || i == 2)
    {
        return i;
    }
    if(mem[i] != 0)
    {
        return mem[i];//���Ҫд�� int count = Dfs(i-1,mem) + Dfs(i-2,mem)֮ǰ����Ϊ��mem[i]����ʱ������Ҫ�ٴηֽ���㣬
                     //ֱ�ӷ��ؼ��ɣ����ҷ��ص���һ��int count = Dfs(i-1,mem) + Dfs(i-2,mem)��
    }
    int count = Dfs(i-1,mem) + Dfs(i-2,mem);
    mem[i] = count;//��¼��ǰ������Ľ⣬��Ϊmem��һ�����飬��¼Ϊi��������Ľ⣬���Բ���Ҫ����
    return count;//��Ҫ����count����һ�㣬���������һ���count
}

int ClimbingStairs(int n)
{
    vector<int> mem(n+1, 0);
    return Dfs(n,mem);
}//�������仯����������ص������ⶼֻ�����һ�Σ�ʱ�临�Ӷ��Ż��� ?(?) 

int main()
{
    int n = 4;
    cout << ClimbingStairs(n) << endl;
    return 0;
}