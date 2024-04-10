#include<iostream>
#include<vector>
#include<string>

using namespace std;

class AdjacencyMatrix
{
private:
    vector<int> Vertices;
    vector<vector<int>> AdjMat;
public:
    AdjacencyMatrix(const vector<int> &vertices, const vector<vector<int>> &edges)
    {
        //添加顶点
        for(auto val : vertices)
        {
            AddVertex(val);
        }
        //添加边
        for(auto &edge : edges)
        {
            AddEdge(edge[0], edge[1]);
        }
    }
    //获取顶点数量
    int Size()
    {
        return Vertices.size();
    }
    //添加顶点
    void AddVertex(int val)
    {
        Vertices.push_back(val);
        //添加一行，该行值全为0
        vector<int> Row(Size(), 0);//vector<int> Row = (Size(), 0),这样写是错误的,
        AdjMat.push_back(Row);//添加行
        for(int i = 0; i < Size(); ++i)//添加列
        {
            AdjMat[i].push_back(0);//在每一行后都添加个0，就相当于添加了一列0
        }
    }
    //删除顶点
    void RemoveVertex(int index)
    {
        if(index >= index)
        {
            cout << "Vertex doesn't exist" << endl;
        }
        Vertices.erase(Vertices.begin() + index);//删除顶点列表中的点
        AdjMat.erase(AdjMat.begin() + index);//删除邻接矩阵该店对应的一行
        for(int i = 0; i < Size(); ++i)//删除邻接矩阵中每一行中对应该点 的每一个元素，相当于删除了该点对应的一列
        {
            AdjMat[i].erase(AdjMat[i].begin() + index);
        }
    }
    //添加边
    void AddEdge(int i, int j)
    {
        if(i < 0 || j < 0 || i >= Size() || j >= Size() || i == j)
        {
            cout << "Can not add edge" << endl;
        }
        else
        {
            AdjMat[i][j] = 1;
            AdjMat[j][i] = 1;
        }
        
    }
    //删除边
    void RemoveEdge(int i, int j)
    {
        if(i < 0 || j < 0 || i >= Size() || j >= Size() || i == j)
        {
            cout << "Can not add edge" << endl;
        }
        AdjMat[i][j] = 0;
        AdjMat[j][i] = 0;
    }
    //打印邻接矩阵
    void Print()
    {
        cout << "Vertices:" << endl;
        for(auto val : Vertices)
        {
            cout << val << " ";
        }
        cout << endl;
        cout << " Adjacency Matix:" << endl;
        for(int i = 0; i < Size(); ++i)
        {
            for(int j = 0; j < Size(); ++j)
            {
                cout << AdjMat[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }


};

int main()
{
    AdjacencyMatrix AM(vector<int> {0,1, 2, 3}, vector<vector<int>>{{0,1},{0,2}});
    AM.AddEdge(0,1);
    AM.AddEdge(0,2);
    AM.AddEdge(0,3);
    AM.AddEdge(1,2);
    AM.AddEdge(3,2);
    AM.AddEdge(1,3);
    AM.Print();
    AM.AddVertex(4);
    AM.AddVertex(5);
    AM.AddVertex(6);
    AM.AddVertex(7);
    AM.AddEdge(5,6);
    AM.AddEdge(5,7);
    AM.AddEdge(2,6);
    AM.AddEdge(3,7);
    AM.Print();



    return 0;
}
