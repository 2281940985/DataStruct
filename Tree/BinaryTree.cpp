#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;
<<<<<<< HEAD
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
=======
//树的节点，包含值、左节点、右节点。
template<typename T>
struct TreeNode
{
    T Val;
    TreeNode *Left;
    TreeNode *Right;
    TreeNode(T val) : Val(val), Left(nullptr), Right(nullptr) {}
};
//广度优先遍历，遵循“逐层推进”的规则，借助“队列”来实现-“先进先出”
//根节点，到第一层节点，再到第二层节点，以此类推
template<typename T>
vector<T> LevelOrdre(TreeNode<T> *root)
{
    queue<TreeNode<T> *> queue;
    queue.push(root);
    vector<T> ret;
    while (!queue.empty())
    {
        TreeNode<T> *node = queue.front();
        queue.pop();
        ret.push_back(node ->Val);
        cout << node ->Val << " ";
        if(node ->Left)
        {
            queue.push(node ->Left);
        }
        if(node ->Right)
        {
            queue.push(node ->Right);
        }
    }
    cout << endl;
    return ret;
}
//前序遍历：先访问root在访问左子树，最后访问右子树；先访问root在访问叶子节点
template<typename T>
void PreOrder(TreeNode<T> *root)
{
    if(root = nullptr)
    return;
    cout << root ->Val << " ";
    PreOrder(root ->Left);
    PreOrder(root ->Right);
}
//中序遍历:先访问左叶子点，在到root，再到右叶子节点；先左再根最后右
template<typename T>
void InOrder(TreeNode<T> *root)
{
    if(root = nullptr)
    return;
    InOrder(root ->Left);
    cout << root ->Val << " ";
    InOrder(root ->Right);
}
//后序遍历：先访问叶子点(左叶子和右叶子)，再到根；最后遍历的是树的总根
template<typename T>
void PostOrder(TreeNode<T> *root)
{
    if(root = nullptr)
    return;
    PostOrder(root ->Left);
    PostOrder(root ->Right);
    cout << root ->Val << endl;  
}
class ArryBinaryTree
{
>>>>>>> 5bd96b80c1f15b95b3cb8dff4b783a0364e9120d

};

int main()
{
<<<<<<< HEAD
    ArryBinaryTree abt(vector<int> {0,1,2,3,4,5,6,7,-1000,8,9,10});
    abt.PreOrder(0);
    cout << endl;
    abt.InOrder(0);
    cout << endl;
    abt.PostOrder(0);
=======

>>>>>>> 5bd96b80c1f15b95b3cb8dff4b783a0364e9120d

    return 0;
}