#include "../Tree/TreeNode.hpp"
#include <unordered_map>
//������������������������������
TreeNode<int> *Dfs(vector<int> &preorder, unordered_map<int, int> &inorder, int i, int l, int r)
{//iΪ���ڵ���preorder�е�������lΪ���ڵ���inorder�е���߽磬rΪ�ұ߽�
//ʹ��unorder_map���洢inorder�еĽڵ㣬������Ҹ��ڵ�Ԫ����inorder�е�����
    if(l > r)
    {
        return nullptr;
    }
    //�������ڵ�
    TreeNode<int> *root = new TreeNode<int>(preorder[i]);
    //����������
    int root_index = inorder[preorder[i]];
    root ->Left = Dfs(preorder, inorder, i+1, l, root_index-1);
    //������������root_index-l�����������ĳ��ȣ�i+1������������ʼ�������ڼ���root_index-l��Ϊ�������ĸ��ڵ�����
    root ->Right =Dfs(preorder, inorder, root_index-l+1+i, root_index+1, r);
    return root;
}
TreeNode<int> *BuildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int,int> inorder_map;
    for(int i = 0; i < inorder.size(); ++i)
    {
        inorder_map[inorder[i]] = i;//����unorder_map����������Ľڵ��ֵ����������
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