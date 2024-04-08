#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;
//树的节点，包含值、左节点、右节点。

//基于数组的二叉树，传入数组，完成树的功能
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
    /* 获取索引为 i 节点的左子节点的索引 */
    int Left(int i)
    {
        return 2 * i + 1;
    }
    /* 获取索引为 i 节点的右子节点的索引 */
    int Right(int i)
    {
        return 2 * i + 2;
    }
    /* 获取索引为 i 节点的父节点的索引 */
    int Parent(int i)
    {
        return (i - 1)/2;
    }
    //层序遍历
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
    //前序遍历
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
    //中序遍历
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
    //后序遍历
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