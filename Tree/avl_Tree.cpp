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
    //��ȡ�ڵ�߶�
    int Height(TreeNode *node)
    { //Ϊʲô�յĽڵ�߶�Ϊ-1; A:��ΪҶ�ӽڵ�ĸ߶�Ϊ0��Ҷ�ӽڵ���ӽڵ�Ϊ�սڵ㣬����Ϊ-1
        return node == nullptr ? -1 : node ->Hei;
    }
    //���½ڵ�߶�
    void UpdateHeight(TreeNode *node)
    {   //�൱�ڵݹ飬Ҫ֪��node��Hei,��Ҫ֪��node���ӽڵ�ĸ߶ȣ��Դ�����ֱ��Ҷ�ӽڵ��Hei = 0������ÿ�������һ���ڵ����Ҫʱ�̸��½ڵ�߶�
        if(node != nullptr)
        {
            node ->Hei = max(Height(node ->Left), Height(node ->Right)) + 1;//Ҷ�ӽڵ��Hei = -1 + 1 = 0
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
    //��������
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
    //��������
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
        if(nodeBalanceFactor > 1)//��ƫ��
        {
            if(BalanceFactor(node ->Left) >= 0)
            {
                return RightRotate(node);
            }
            else
            { //��ת��һ��ע�⣬ִ����ת�����󣬷��ص��������ĸ��ڵ㣬һ��Ҫ��Ӧ��
              //������ִ��������ת����������������������node���ӽڵ㣬������node�������ṹ�����˱仯
              //��ʱ������������µ�root���ظ�node��Leftָ����Ϊ���ָ��ӽڵ��ϵ��δ�ı䡣
                node ->Left = LeftRotate(node ->Left);
                return RightRotate(node);//������ת��ֱ�ӷ��ؾ��У�Ҳ����Ҫ���Ǹ��ӹ�ϵ
            }

        }
        else if(nodeBalanceFactor < -1)//��ƫ��
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
        return node;//ƽ����������Ҫ��ת
    }
    //����ڵ�
    TreeNode *InsertNodeHelper(TreeNode *node, int val)
    {
        if(node == nullptr)//node��������Ҫ����ڵ�ĸ��ڵ�
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
            return node;//Ҫ����Ľڵ��Ѿ����ڣ�ֱ�ӷ��ص���һ�����
        }
        UpdateHeight(node);
        node = Rotate(node);
        return node;//���ص��������ĸ��ڵ㣬�ص���һ�����¸��½ڵ�߶Ⱥ���ת���Ե����ϵݹ�
        
    }
    void InsertNode(int val)
    {
        Root = InsertNodeHelper(Root,val);//��Root��ʼִ�е������룬Ȼ���Ե����ϲ��ϸ��½ڵ�߶�
    }
    TreeNode *RemoveNodeHelper(TreeNode* node, int val)
    {
        if(node == nullptr)
        {
            return node;
        }
        if(val > node ->Val)
        {
            node ->Right = RemoveNodeHelper(node ->Right, val);//node��������Ҫɾ���ڵ�ĸ��ڵ�
        }
        else if(val < node ->Val)
        { //��һ��node->Left�Ǳ������ڵ�node��ָ�򣬺���RemoveNodeHelper(node ->Left, val)���node->Left�Ǵ�����ӽڵ�
         //�ӽڵ�ִ�����ɲ����󷵻�
            node ->Left = RemoveNodeHelper(node ->Left, val);
        }
        else//���˵���ҵ��˽ڵ㣬ִ��ɾ������
        {
            if(node ->Left == nullptr || node ->Right ==nullptr)//��Ϊ1��0
            {
                TreeNode *child = node ->Left == nullptr ? node ->Right : node ->Left;
                if(child == nullptr)//Ҷ�ӽڵ�
                {
                    delete node;//ֱ��ɾ������
                    return nullptr;//���ؿ���Ϊ��һ���ҵ���ɾ���Ľڵ㣬ɾ���󸸽ڵ��ָ��Ҫ����Ϊ�ղ�������ɾ��
                }
                else//��Ϊ1�Ľڵ�
                {
                    delete node;//��Ϊ����֪��node�ĸ��ڵ㣬���Բ��ø�ֵָ�����
                    node = child;//��nodeɾ����ֱ����node��childָ��ͬһ�����򣬴�ʱǧ����delete child
                    //��Ϊ��ɾ������ָ��ָ������򣬻ᵼ��node��child��ʧЧ
                }
            }
            else//ɾ����Ϊ2�Ľڵ�,����Ҫ�����ҵ�һ���µĸ��ڵ���������ɾ���Ľڵ�
            {
                TreeNode *tmp = node ->Right;//��������������ߵĽڵ���Ϊ�µĸ��ڵ�
                
                while (tmp ->Left)//��Ϊtmp,��tmpΪ��ʱ������ѭ������ʱtmpû�κ��ã���Ҫ��ʱtmp�ĸ��ڵ�
                {
                    tmp = tmp ->Left;
                }
                int tmp_val = tmp ->Val;
                node ->Val = tmp_val;//�Ͷ���������һ��
                RemoveNodeHelper(tmp,val);
                
            }
        }
        UpdateHeight(node);//ÿһ�㶼��Ҫ����һ�νڵ�߶�
        node = Rotate(node);//�Ե�����ִ����ת����
        return node;//���ص���һ�����ִ�и��½ڵ�߶ȣ��ж��Ƿ���Ҫ��ת
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
