#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;
<<<<<<< HEAD
//Ê÷µÄ½Úµã£¬°üº¬Öµ¡¢×ó½Úµã¡¢ÓÒ½Úµã¡£

//»ùÓÚÊı×éµÄ¶ş²æÊ÷£¬´«ÈëÊı×é£¬Íê³ÉÊ÷µÄ¹¦ÄÜ
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
    /* »ñÈ¡Ë÷ÒıÎª i ½ÚµãµÄ×ó×Ó½ÚµãµÄË÷Òı */
    int Left(int i)
    {
        return 2 * i + 1;
    }
    /* »ñÈ¡Ë÷ÒıÎª i ½ÚµãµÄÓÒ×Ó½ÚµãµÄË÷Òı */
    int Right(int i)
    {
        return 2 * i + 2;
    }
    /* »ñÈ¡Ë÷ÒıÎª i ½ÚµãµÄ¸¸½ÚµãµÄË÷Òı */
    int Parent(int i)
    {
        return (i - 1)/2;
    }
    //²ãĞò±éÀú
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
    //Ç°Ğò±éÀú
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
    //ÖĞĞò±éÀú
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
    //ºóĞò±éÀú
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
//æ ‘çš„èŠ‚ç‚¹ï¼ŒåŒ…å«å€¼ã€å·¦èŠ‚ç‚¹ã€å³èŠ‚ç‚¹ã€‚
template<typename T>
struct TreeNode
{
    T Val;
    TreeNode *Left;
    TreeNode *Right;
    TreeNode(T val) : Val(val), Left(nullptr), Right(nullptr) {}
};
//å¹¿åº¦ä¼˜å…ˆéå†ï¼Œéµå¾ªâ€œé€å±‚æ¨è¿›â€çš„è§„åˆ™ï¼Œå€ŸåŠ©â€œé˜Ÿåˆ—â€æ¥å®ç°-â€œå…ˆè¿›å…ˆå‡ºâ€
//æ ¹èŠ‚ç‚¹ï¼Œåˆ°ç¬¬ä¸€å±‚èŠ‚ç‚¹ï¼Œå†åˆ°ç¬¬äºŒå±‚èŠ‚ç‚¹ï¼Œä»¥æ­¤ç±»æ¨
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
//å‰åºéå†ï¼šå…ˆè®¿é—®rootåœ¨è®¿é—®å·¦å­æ ‘ï¼Œæœ€åè®¿é—®å³å­æ ‘ï¼›å…ˆè®¿é—®rootåœ¨è®¿é—®å¶å­èŠ‚ç‚¹
template<typename T>
void PreOrder(TreeNode<T> *root)
{
    if(root = nullptr)
    return;
    cout << root ->Val << " ";
    PreOrder(root ->Left);
    PreOrder(root ->Right);
}
//ä¸­åºéå†:å…ˆè®¿é—®å·¦å¶å­ç‚¹ï¼Œåœ¨åˆ°rootï¼Œå†åˆ°å³å¶å­èŠ‚ç‚¹ï¼›å…ˆå·¦å†æ ¹æœ€åå³
template<typename T>
void InOrder(TreeNode<T> *root)
{
    if(root = nullptr)
    return;
    InOrder(root ->Left);
    cout << root ->Val << " ";
    InOrder(root ->Right);
}
//ååºéå†ï¼šå…ˆè®¿é—®å¶å­ç‚¹(å·¦å¶å­å’Œå³å¶å­)ï¼Œå†åˆ°æ ¹ï¼›æœ€åéå†çš„æ˜¯æ ‘çš„æ€»æ ¹
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