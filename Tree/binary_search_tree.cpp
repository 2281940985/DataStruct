#include"TreeNode.hpp"
//���ҽڵ�
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
    //��ȡ���ڵ�,Root��˽�б��������ǿ���ͨ�����к������˽�б���
    TreeNode<T> * GetRoot()
    {
        return Root;
    }
    void FreeMemory(TreeNode<T> *root)
    {
        if(root ==  nullptr)//�ڵ�������ǰ�к������ʱ���ڵ�������֮ǰһ��Ҫ��ǰ�ж�ָ���Ƿ�Ϊ�գ�Ϊ��һ��Ҫ����ѭ������������Ұָ��
        {
            return;
        }
        FreeMemory(root ->Left);
        FreeMemory(root ->Right);
        delete root;
    }
    //���ҽڵ�
    TreeNode<T> *Searching(T num)
    {
        TreeNode<T> *cur = Root;
        while(cur)
        {
            if(num > cur ->Val)
            {
                cur = cur ->Right;
            }
            else if(num < cur ->Val)//�мǲ���ʹ�ö��if,if,��Ϊÿ��ifִ�к󶼻�ı�cur��ֵ��Ȼ����ȥִ����һ��if���
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
    //����ڵ�,pre���游�ڵ㣬curһֱ����ѭ����cur����Ϊ��ʱ��pre����Ϊ�գ���pre�������ڵ㼴��
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
            else//���ʱ�򷵻أ������������
            {
                return;
            }
        }
        TreeNode<T> *node = new TreeNode<T> (num);//��������ڵ�
        if(num > pre ->Val)//�ж�����ڵ�Ӧ�ò���pre����߻����ұ�
        {
            pre ->Right = node;
        }
        else
        {
            pre ->Left = node;
        }
    }
    //ɾ���ڵ�
    void RemoveNode(T num)
    {
        if(Root == nullptr)
        {
            return;
        }
        TreeNode<T> * cur = Root;
        TreeNode<T> *pre = nullptr;
        while (cur)//cur����Ҫɾ���Ľڵ㣬pre����Ҫɾ���ڵ�ĸ��ڵ�
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
                break;//��Ⱦ�����ѭ����ǧ����return
            }

        }
        //�ӽڵ����Ϊ0/1,ֱ�ӽ�cur���ӽڵ㴫��pre���ӽڵ㣬��Ϊpre��һ���ӽڵ���cur������cur��ɾ����
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
        else//�ӽڵ�����Ϊ2������Ҫɾ���Ľڵ�(cur)Ѱ������������Сֵ--������������� ���� �����������ֵ--�����������ֵ
        {   //����ֵ����Ҫɾ���Ľڵ�(cur),��Ϊ�µ������ĸ��ڵ㣬Ȼ��ɾ����ֵ�Ľڵ�
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