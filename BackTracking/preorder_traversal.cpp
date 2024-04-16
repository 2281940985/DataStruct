#include"../Tree/TreeNode.hpp"

void PreOrderWithPath(TreeNode<int> *root, vector<int> &path, vector<vector<int>> &res)
{
    //剪枝
    if(root == nullptr)
    {
        return;//回溯首先要考虑当函数走到底要怎么操作，这里是返回，有些情况是返回一个值
    }
    //尝试
    path.push_back(root ->Val);//先添加path，找到符合要求的path后在存入res
    if (root ->Val == 7)
    {
        res.push_back(path);
    }
    PreOrderWithPath(root ->Left, path, res);
    PreOrderWithPath(root ->Right, path, res);
    //回退
    path.pop_back();//执行到这说明新添加进的path不是需要的，要删除返回到上一层继续搜索
}
int main()
{
    vector<vector<int>> res;
    vector<int> path;
    TreeNode<int> *root = new TreeNode<int>(1);
    root ->Left = new TreeNode<int>(2);
    root ->Right = new TreeNode<int>(7);
    root ->Left ->Left = new TreeNode<int>(4);
    root ->Left ->Right = new TreeNode<int>(5);
    root ->Right ->Left = new TreeNode<int>(6);
    root ->Right ->Right = new TreeNode<int>(7);
    PreOrderWithPath(root, path, res);
    for(auto &v : res)
    {
        for(auto &i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
