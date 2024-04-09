#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct TreeNode
{
    int Val;
    int Hei;
    TreeNode *Left;
    TreeNode *Right;
    TreeNode(int x) : Val(x), Hei(0), Left(nullptr), Right(nullptr) {}
    ~TreeNode(){}
};
class AVLTree
{
public:
    TreeNode *Root;
    AVLTree() : Root(nullptr){}
    //获取节点高度
    int Height(TreeNode *node)
    { //为什么空的节点高度为-1; A:因为叶子节点的高度为0，叶子节点的子节点为空节点，所以为-1
        return node == nullptr ? -1 : node ->Hei;
    }
    //更新节点高度
    void UpdateHeight(TreeNode *node)
    {   //相当于递归，要知道node的Hei,需要知道node的子节点的高度，以此类推直到叶子节点的Hei = 0；所以每次新添加一个节点必须要时刻更新节点高度
        if(node != nullptr)
        {
            node ->Hei = max(Height(node ->Left), Height(node ->Right)) + 1;//叶子节点的Hei = -1 + 1 = 0
        }
        return;
        
    }
    int BalanceFactor(TreeNode *node)
    {
        if(node == nullptr)
        {
            return 0;
        }
        return Height(node ->Left) - Height(node ->Right);
    }
    //右旋操作
    TreeNode *RightRotate(TreeNode *node)
    {
        if(node == nullptr)
        {
            return nullptr;
        }
        TreeNode *child = node ->Left;
        TreeNode *grandchild = child ->Right;
        child ->Right = node;
        node ->Left = grandchild;
        UpdateHeight(node);
        UpdateHeight(child);
        UpdateHeight(grandchild);
        return child;
    }
    //左旋操作
    TreeNode *LeftRotate(TreeNode *node)
    {
        if(node == nullptr)
        {
            return nullptr;
        }
        TreeNode *child = node ->Right;
        TreeNode *grandchild = node ->Left;
        child ->Left = node;
        node ->Right = grandchild;
        UpdateHeight(node);
        UpdateHeight(child);
        UpdateHeight(grandchild);
        return child;
    }
    TreeNode *Rotate(TreeNode *node)
    {
        int nodeBalanceFactor = BalanceFactor(node);
        if(nodeBalanceFactor > 1)//左偏树
        {
            if(BalanceFactor(node ->Left) >= 0)
            {
                return RightRotate(node);
            }
            else
            { //旋转后一定注意，执行旋转操作后，返回的是子树的根节点，一定要对应上
              //尤其是执行两次旋转操作，先右旋，右旋的是node的子节点，右旋后node的子树结构发生了变化
              //此时必须把子树的新的root返回给node的Left指向，因为这种父子节点关系并未改变。
                node ->Left = LeftRotate(node ->Left);
                return RightRotate(node);//最终旋转，直接返回就行，也不需要考虑父子关系
            }

        }
        else if(nodeBalanceFactor < -1)//右偏树
        {
            if(BalanceFactor(node ->Right) <= 0)
            {
                return LeftRotate(node);
            }
            else
            {
                node ->Right = RightRotate(node ->Right);
                return LeftRotate(node);
            }
        }
        return node;//平衡树，不需要旋转
    }
    //插入节点
    TreeNode *InsertNodeHelper(TreeNode *node, int val)
    {
        if(node == nullptr)//node就是我们要插入节点的父节点
        {
            return new TreeNode(val);
        }
        if(val < node ->Val)
        {
            node ->Left = InsertNodeHelper(node ->Left, val);
        }
        else if(val > node ->Val)
        {
            node ->Right = InsertNodeHelper(node ->Right, val);   
        }
        else
        {
            return node;//要插入的节点已经存在，直接返回到上一层迭代
        }
        UpdateHeight(node);
        node = Rotate(node);
        return node;//返回的是子树的根节点，回到上一层重新更新节点高度和旋转。自底向上递归
        
    }
    void InsertNode(int val)
    {
        Root = InsertNodeHelper(Root,val);//从Root开始执行迭代插入，然后自底向上不断更新节点高度
    }
    TreeNode *RemoveNodeHelper(TreeNode* node, int val)
    {
        if(node == nullptr)
        {
            return node;
        }
        if(val > node ->Val)
        {
            node ->Right = RemoveNodeHelper(node ->Right, val);//node就是我们要删除节点的父节点
        }
        else if(val < node ->Val)
        { //第一个node->Left是表明父节点node的指向，函数RemoveNodeHelper(node ->Left, val)里的node->Left是传入的子节点
         //子节点执行若干操作后返回
            node ->Left = RemoveNodeHelper(node ->Left, val);
        }
        else//相等说明找到了节点，执行删除操作
        {
            if(node ->Left == nullptr || node ->Right ==nullptr)//度为1或0
            {
                TreeNode *child = node ->Left == nullptr ? node ->Right : node ->Left;
                if(child == nullptr)//叶子节点
                {
                    delete node;//直接删除就行
                    return nullptr;//返回空因为这一层找到了删除的节点，删除后父节点的指向要重置为空才算完整删除
                }
                else//度为1的节点
                {
                    delete node;//因为并不知道node的父节点，所以采用赋值指针操作
                    node = child;//把node删除后，直接让node和child指向同一块区域，此时千万不能delete child
                    //因为这删除的是指针指向的区域，会导致node，child都失效
                }
            }
            else//删除度为2的节点,必须要重新找到一个新的根节点代替这个待删除的节点
            {
                TreeNode *tmp = node ->Right;//找右子树的最左边的节点作为新的根节点
                
                while (tmp ->Left)//若为tmp,则tmp为空时就跳出循环，此时tmp没任何用，需要的时tmp的父节点
                {
                    tmp = tmp ->Left;
                }
                int tmp_val = tmp ->Val;
                node ->Val = tmp_val;//和二叉搜索树一样
                RemoveNodeHelper(tmp,val);
                
            }
        }
        UpdateHeight(node);//每一层都需要更新一次节点高度
        node = Rotate(node);//自底向上执行旋转操作
        return node;//返回到上一层继续执行更新节点高度，判断是否需要旋转
    }
    void RemoveNode(int val)
    {
        Root = RemoveNodeHelper(Root, val);
    }
};
void PreOrder(TreeNode *node)
{
    if(node == nullptr)
    {
        return;
    }
    cout << node ->Val << "  ";
    PreOrder(node ->Left);
    PreOrder(node ->Right);
}
int main()
{
    AVLTree avl;
    avl.InsertNode(7);
    avl.InsertNode(1);
    avl.InsertNode(3);
    avl.InsertNode(4);
    avl.InsertNode(5);
    avl.InsertNode(2);
    avl.InsertNode(0);
    avl.InsertNode(-1);
    avl.InsertNode(6);
    avl.InsertNode(-66);
    avl.RemoveNode(-66);
    PreOrder(avl.Root);
    return 0;
}
