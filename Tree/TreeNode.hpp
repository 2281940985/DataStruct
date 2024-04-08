#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;
template<typename T>
struct TreeNode
{
    T Val;
    TreeNode *Left;
    TreeNode *Right;
    TreeNode(T val) : Val(val), Left(nullptr), Right(nullptr) {}
};
//������ȱ�������ѭ������ƽ����Ĺ��򣬽��������С���ʵ��-���Ƚ��ȳ���
//���ڵ㣬����һ��ڵ㣬�ٵ��ڶ���ڵ㣬�Դ�����
template<typename T>
vector<T> LevelOrder(TreeNode<T> *root)
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
//ǰ��������ȷ���root�ڷ��������������������������ȷ���root�ڷ���Ҷ�ӽڵ�
template<typename T>
void PreOrder(TreeNode<T> *root)
{
    
    if(root == nullptr)
    {
        return;
    }
    
    cout << root ->Val << " ";
    PreOrder(root ->Left);
    PreOrder(root ->Right);
    
}
//�������:�ȷ�����Ҷ�ӵ㣬�ڵ�root���ٵ���Ҷ�ӽڵ㣻�����ٸ������
template<typename T>
void InOrder(TreeNode<T> *root)
{
    if(root == nullptr)
    return;
    InOrder(root ->Left);
    cout << root ->Val << " ";
    InOrder(root ->Right);
}
//����������ȷ���Ҷ�ӵ�(��Ҷ�Ӻ���Ҷ��)���ٵ��������������������ܸ�
template<typename T>
void PostOrder(TreeNode<T> *root)
{
    if(root == nullptr)
    return;
    PostOrder(root ->Left);
    PostOrder(root ->Right);
    cout << root ->Val << " ";  
}