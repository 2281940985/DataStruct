#include "../Tree/TreeNode.hpp"
#include <unordered_map>
//构建二叉树辅助函数————分治
TreeNode<int> *Dfs(vector<int> &preorder, unordered_map<int, int> &inorder, int i, int l, int r)
{//i为根节点在preorder中的索引，l为根节点在inorder中的左边界，r为右边界
//使用unorder_map来存储inorder中的节点，方便查找根节点元素在inorder中的索引
    if(l > r)
    {
        return nullptr;
    }
    //创建根节点
    TreeNode<int> *root = new TreeNode<int>(preorder[i]);
    //创建左子树
    int root_index = inorder[preorder[i]];
    root ->Left = Dfs(preorder, inorder, i+1, l, root_index-1);
    //创建右子树，root_index-l代表左子树的长度，i+1代表左子树起始索引，在加上root_index-l即为右子树的根节点索引
    root ->Right =Dfs(preorder, inorder, root_index-l+1+i, root_index+1, r);
    return root;
}
TreeNode<int> *BuildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int,int> inorder_map;
    for(int i = 0; i < inorder.size(); ++i)
    {
        inorder_map[inorder[i]] = i;//创建unorder_map将中序遍历的节点的值与索引存入
    }
    return Dfs(preorder, inorder_map, 0, 0, inorder.size()-1);
}

int main()
{
    vector<int> preorder = {3,9,2,4,6,0,7,1,5};
    vector<int> inorder = {4,2,6,9,0,3,1,7,5};
    TreeNode<int> *root = BuildTree(preorder, inorder);
    LevelOrder(root);
    return 0;
}