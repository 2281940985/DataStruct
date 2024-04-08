#include"TreeNode.hpp"
//查找节点
template<typename T>
class BinarySearchTree
{
private:
    TreeNode<T> *Root;
public:
    BinarySearchTree() : Root(nullptr){}
    ~BinarySearchTree()
    {
        cout << "destructed" << "  ";
        FreeMemory(Root);
    }
    //获取根节点,Root是私有变量，但是可以通过公有函数获得私有变量
    TreeNode<T> * GetRoot()
    {
        return Root;
    }
    void FreeMemory(TreeNode<T> *root)
    {
        if(root ==  nullptr)//在调用树的前中后序遍历时，在迭代调用之前一定要提前判断指针是否为空，为空一定要跳出循环，否则会出现野指针
        {
            return;
        }
        FreeMemory(root ->Left);
        FreeMemory(root ->Right);
        delete root;
    }
    //查找节点
    TreeNode<T> *Searching(T num)
    {
        TreeNode<T> *cur = Root;
        while(cur)
        {
            if(num > cur ->Val)
            {
                cur = cur ->Right;
            }
            else if(num < cur ->Val)//切记不能使用多个if,if,因为每个if执行后都会改变cur的值，然后又去执行下一个if语句
            {
                cur = cur ->Left;
            }
            else
            {
                break;
            }
        }
        return cur;
    }
    //插入节点,pre保存父节点，cur一直迭代循环，cur迭代为空时，pre并不为空，在pre后面插入节点即可
    void InsertNode(T num)
    {
        if(Root == nullptr)
        {
            Root = new TreeNode<T>(num);
        }
        TreeNode<T> *cur = Root;
        TreeNode<T> *pre = nullptr;
        while (cur)
        {   
            if(num > cur ->Val)
            {
                pre = cur;
                cur = cur ->Right;
            }
            else if(num < cur ->Val)
            {
                pre = cur;
                cur = cur ->Left;
            }
            else//相等时候返回，结束这个函数
            {
                return;
            }
        }
        TreeNode<T> *node = new TreeNode<T> (num);//生成这个节点
        if(num > pre ->Val)//判断这个节点应该插在pre的左边还是右边
        {
            pre ->Right = node;
        }
        else
        {
            pre ->Left = node;
        }
    }
    //删除节点
    void RemoveNode(T num)
    {
        if(Root == nullptr)
        {
            return;
        }
        TreeNode<T> * cur = Root;
        TreeNode<T> *pre = nullptr;
        while (cur)//cur保存要删除的节点，pre保存要删除节点的父节点
        {
            if(num > cur ->Val)
            {
                pre = cur;
                cur = cur ->Right;
            }
            else if(num < cur ->Val)
            {
                pre = cur;
                cur = cur ->Left;
            }
            else
            {
                break;//相等就跳出循环，千万不能return
            }

        }
        //子节点度数为0/1,直接将cur的子节点传给pre的子节点，因为pre的一个子节点是cur，但是cur被删除了
        if(cur ->Left == nullptr || cur ->Right == nullptr)
        {   
            TreeNode<T> *child = cur ->Left != nullptr ? cur ->Left : cur ->Right;
            if (cur != Root)
            {
                if(pre ->Left == cur)
                {
                    pre ->Left = child;
                }
                else
                {
                    pre ->Right = child;
                }
            }
            else
            {
                Root = child;
            }
            delete cur;
            
        }
        else//子节点数量为2，在需要删除的节点(cur)寻找右子树的最小值--右子树的最左边 或者 左子树的最大值--左子树的最大值
        {   //将该值赋给要删除的节点(cur),作为新的子树的根节点，然后删除该值的节点
            TreeNode<T> *tmp = cur ->Right;
            while (tmp ->Left)
            {
                tmp = tmp ->Left;
            }
            int tmpVal = tmp ->Val;
            RemoveNode(tmp ->Val);
            cur ->Val = tmpVal;
        }  
    }
};
int main()
{
    BinarySearchTree<int> bst;
    bst.InsertNode(7);
    bst.InsertNode(1);
    bst.InsertNode(2);
    bst.InsertNode(3);
    bst.InsertNode(4);
    bst.InsertNode(5);
    bst.InsertNode(6);
    bst.InsertNode(7);
    bst.InsertNode(8);
    bst.InsertNode(9);
    bst.InsertNode(10);
    bst.InsertNode(20);
    bst.InsertNode(30);
    bst.InsertNode(-19);
    bst.InsertNode(50);
    bst.InsertNode(60);
    bst.InsertNode(70);
    bst.InsertNode(-45);
    LevelOrder(bst.GetRoot());
    bst.RemoveNode(1);
    LevelOrder(bst.GetRoot());//Perfect
    PreOrder(bst.GetRoot());
    cout << endl;
    InOrder(bst.GetRoot());
    cout << endl;
    PostOrder(bst.GetRoot());
    cout << endl;
    cout << bst.Searching(10) ->Right ->Val << endl;


    


    return 0;
}