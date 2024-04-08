#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;
//���Ľڵ㣬����ֵ����ڵ㡢�ҽڵ㡣

//��������Ķ��������������飬������Ĺ���
class ArryBinaryTree
{
private:
    vector<int> Tree;
public:
    ArryBinaryTree(vector<int> arry) : Tree(arry) {}
    int Size()
    {
        return Tree.size();
    }
    int Searching(int i)
    {
        if (i < 0 || i > Size())
        {
            return -1000;
        }
        return Tree[i];
        
    }
    /* ��ȡ����Ϊ i �ڵ�����ӽڵ������ */
    int Left(int i)
    {
        return 2 * i + 1;
    }
    /* ��ȡ����Ϊ i �ڵ�����ӽڵ������ */
    int Right(int i)
    {
        return 2 * i + 2;
    }
    /* ��ȡ����Ϊ i �ڵ�ĸ��ڵ������ */
    int Parent(int i)
    {
        return (i - 1)/2;
    }
    //�������
    vector<int> LeverOrder()
    {
        vector<int> ret;
        for(int i = 0; i < Size(); i ++)
        {
            if(Tree[i] != -1000)
            {
                ret.push_back(Tree[i]);
                cout << Tree[i] << " ";
            }
        }
        return ret;
    }
    //ǰ�����
    void PreOrder(int i)
    {
        if(Tree[i] == -1000 || i >= Size())
        {
            return;
        }
        cout << Tree[i] << " ";
        PreOrder(Left(i));
        PreOrder(Right(i));

    }
    //�������
    void InOrder(int i)
    {
        if(Tree[i] == -1000 || i >= Size())
        {
            return;
        }
        InOrder(Left(i));
        cout << Tree[i] << " ";
        InOrder(Right(i));
    }
    //�������
    void PostOrder(int i)
    {
        if(Tree[i] == -1000 || i >= Size())
        {
            return;
        }       
        PostOrder(Left(i));
        PostOrder(Right(i));
        cout << Tree[i] << " ";
    }

};

int main()
{
    ArryBinaryTree abt(vector<int> {0,1,2,3,4,5,6,7,-1000,8,9,10});
    abt.PreOrder(0);
    cout << endl;
    abt.InOrder(0);
    cout << endl;
    abt.PostOrder(0);

    return 0;
}