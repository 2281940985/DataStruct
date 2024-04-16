#include"../Tree/TreeNode.hpp"

void PreOrderWithPath(TreeNode<int> *root, vector<int> &path, vector<vector<int>> &res)
{
    //��֦
    if(root == nullptr)
    {
        return;//��������Ҫ���ǵ������ߵ���Ҫ��ô�����������Ƿ��أ���Щ����Ƿ���һ��ֵ
    }
    //����
    path.push_back(root ->Val);//�����path���ҵ�����Ҫ���path���ڴ���res
    if (root ->Val == 7)
    {
        res.push_back(path);
    }
    PreOrderWithPath(root ->Left, path, res);
    PreOrderWithPath(root ->Right, path, res);
    //����
    path.pop_back();//ִ�е���˵������ӽ���path������Ҫ�ģ�Ҫɾ�����ص���һ���������
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
