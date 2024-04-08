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
//广度优先遍历，遵循“逐层推进”的规则，借助“队列”来实现-“先进先出”
//根节点，到第一层节点，再到第二层节点，以此类推
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
//前序遍历：先访问root在访问左子树，最后访问右子树；先访问root在访问叶子节点
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
//中序遍历:先访问左叶子点，在到root，再到右叶子节点；先左再根最后右
template<typename T>
void InOrder(TreeNode<T> *root)
{
    if(root == nullptr)
    return;
    InOrder(root ->Left);
    cout << root ->Val << " ";
    InOrder(root ->Right);
}
//后序遍历：先访问叶子点(左叶子和右叶子)，再到根；最后遍历的是树的总根
template<typename T>
void PostOrder(TreeNode<T> *root)
{
    if(root == nullptr)
    return;
    PostOrder(root ->Left);
    PostOrder(root ->Right);
    cout << root ->Val << " ";  
}