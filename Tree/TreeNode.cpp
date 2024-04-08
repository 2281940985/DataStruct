#include"TreeNode.hpp"
int main()
{
    TreeNode<string> *root = new TreeNode<string>("InitialZ");
    TreeNode<string> *node1 = new TreeNode<string>("Liwangda");
    TreeNode<string> *node2 = new TreeNode<string>("Heyiming");
    TreeNode<string> *node3 = new TreeNode<string>("DuanJianghua");
    TreeNode<string> *node4 = new TreeNode<string>("Yutao");
    TreeNode<string> *node5 = new TreeNode<string>("ShengKuo");
    TreeNode<string> *node6 = new TreeNode<string>("Liuxiangyu");
    root ->Left = node1;
    root ->Right = node2;
    node1 ->Left = node4;
    node1 ->Right = node5;
    node2 ->Left = node3;
    node2 ->Right = node6;
    LevelOrder(root);
    PreOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    PostOrder(root);
    return 0;
}
