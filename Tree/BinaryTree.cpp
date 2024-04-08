#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;
<<<<<<< HEAD
//树的节点，包含值、左节点、右节点。

//基于数组的二叉树，传入数组，完成树的功能
class ArryBinaryTree
{
private:
    vector<int> Tree;
public:
    ArryBinaryTree(vector<int> arry) : Tree(arry) {}
    int Size()
    {
        return Tree.size();
    }
    int Searching(int i)
    {
        if (i < 0 || i > Size())
        {
            return -1000;
        }
        return Tree[i];
        
    }
    /* 获取索引为 i 节点的左子节点的索引 */
    int Left(int i)
    {
        return 2 * i + 1;
    }
    /* 获取索引为 i 节点的右子节点的索引 */
    int Right(int i)
    {
        return 2 * i + 2;
    }
    /* 获取索引为 i 节点的父节点的索引 */
    int Parent(int i)
    {
        return (i - 1)/2;
    }
    //层序遍历
    vector<int> LeverOrder()
    {
        vector<int> ret;
        for(int i = 0; i < Size(); i ++)
        {
            if(Tree[i] != -1000)
            {
                ret.push_back(Tree[i]);
                cout << Tree[i] << " ";
            }
        }
        return ret;
    }
    //前序遍历
    void PreOrder(int i)
    {
        if(Tree[i] == -1000 || i >= Size())
        {
            return;
        }
        cout << Tree[i] << " ";
        PreOrder(Left(i));
        PreOrder(Right(i));

    }
    //中序遍历
    void InOrder(int i)
    {
        if(Tree[i] == -1000 || i >= Size())
        {
            return;
        }
        InOrder(Left(i));
        cout << Tree[i] << " ";
        InOrder(Right(i));
    }
    //后序遍历
    void PostOrder(int i)
    {
        if(Tree[i] == -1000 || i >= Size())
        {
            return;
        }       
        PostOrder(Left(i));
        PostOrder(Right(i));
        cout << Tree[i] << " ";
    }
=======
//鏍戠殑鑺傜偣锛屽寘鍚�笺�佸乏鑺傜偣銆佸彸鑺傜偣銆�
template<typename T>
struct TreeNode
{
    T Val;
    TreeNode *Left;
    TreeNode *Right;
    TreeNode(T val) : Val(val), Left(nullptr), Right(nullptr) {}
};
//骞垮害浼樺厛閬嶅巻锛岄伒寰�滈�愬眰鎺ㄨ繘鈥濈殑瑙勫垯锛屽�熷姪鈥滈槦鍒椻�濇潵瀹炵幇-鈥滃厛杩涘厛鍑衡��
//鏍硅妭鐐癸紝鍒扮涓�灞傝妭鐐癸紝鍐嶅埌绗簩灞傝妭鐐癸紝浠ユ绫绘帹
template<typename T>
vector<T> LevelOrdre(TreeNode<T> *root)
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
//鍓嶅簭閬嶅巻锛氬厛璁块棶root鍦ㄨ闂乏瀛愭爲锛屾渶鍚庤闂彸瀛愭爲锛涘厛璁块棶root鍦ㄨ闂彾瀛愯妭鐐�
template<typename T>
void PreOrder(TreeNode<T> *root)
{
    if(root = nullptr)
    return;
    cout << root ->Val << " ";
    PreOrder(root ->Left);
    PreOrder(root ->Right);
}
//涓簭閬嶅巻:鍏堣闂乏鍙跺瓙鐐癸紝鍦ㄥ埌root锛屽啀鍒板彸鍙跺瓙鑺傜偣锛涘厛宸﹀啀鏍规渶鍚庡彸
template<typename T>
void InOrder(TreeNode<T> *root)
{
    if(root = nullptr)
    return;
    InOrder(root ->Left);
    cout << root ->Val << " ";
    InOrder(root ->Right);
}
//鍚庡簭閬嶅巻锛氬厛璁块棶鍙跺瓙鐐�(宸﹀彾瀛愬拰鍙冲彾瀛�)锛屽啀鍒版牴锛涙渶鍚庨亶鍘嗙殑鏄爲鐨勬�绘牴
template<typename T>
void PostOrder(TreeNode<T> *root)
{
    if(root = nullptr)
    return;
    PostOrder(root ->Left);
    PostOrder(root ->Right);
    cout << root ->Val << endl;  
}
class ArryBinaryTree
{
>>>>>>> 5bd96b80c1f15b95b3cb8dff4b783a0364e9120d

};

int main()
{
<<<<<<< HEAD
    ArryBinaryTree abt(vector<int> {0,1,2,3,4,5,6,7,-1000,8,9,10});
    abt.PreOrder(0);
    cout << endl;
    abt.InOrder(0);
    cout << endl;
    abt.PostOrder(0);
=======

>>>>>>> 5bd96b80c1f15b95b3cb8dff4b783a0364e9120d

    return 0;
}