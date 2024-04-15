#include <iostream>
#include <vector>

using namespace std;

//�ƶ�һ��Բ��
void Move(vector<int> &src, vector<int> &tar)
{
    int top = src.back();
    src.pop_back();
    tar.push_back(top);
}

//�ƶ�n��Բ�̺�n-1����ȫһ����ֻ�����ƶ�n��Բ���ǽ�n-1��Բ���ƶ���buf��Ȼ���ƶ�һ��Բ�̵�tar���ٽ�n-1��Բ���ƶ���tar����
void Dfs(int i, vector<int> &src, vector<int> &buf, vector<int> &tar)
{
    if(i == 1)
    {
        Move(src, tar);//ֻʣһ��Բ��ֱ����һ���ƶ�����
        return;
    }
    Dfs(i - 1, src, tar, buf);//ע�������buf��tar��λ��,�ƶ�n-1��Բ�̵�buf
    Move(src, tar);//�����һ��Բ���ƶ���tar
    Dfs(i - 1, buf, src, tar);//��Buffer����n-1��Բ���ƶ���tar
}
//��⺺ŵ��
void SolveHanota(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int n = A.size();
    Dfs(n, A, B, C);
}
int main()
{
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B;
    vector<int> C;
    SolveHanota(A, B, C);
    for(int i = 0; i < C.size(); i++)
    {
        cout << C[i] << " ";
    }
    cout << endl;
    return 0;
}