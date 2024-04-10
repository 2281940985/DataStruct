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
        //��Ӷ���
        for(auto val : vertices)
        {
            AddVertex(val);
        }
        //��ӱ�
        for(auto &edge : edges)
        {
            AddEdge(edge[0], edge[1]);
        }
    }
    //��ȡ��������
    int Size()
    {
        return Vertices.size();
    }
    //��Ӷ���
    void AddVertex(int val)
    {
        Vertices.push_back(val);
        //���һ�У�����ֵȫΪ0
        vector<int> Row(Size(), 0);//vector<int> Row = (Size(), 0),����д�Ǵ����,
        AdjMat.push_back(Row);//�����
        for(int i = 0; i < Size(); ++i)//�����
        {
            AdjMat[i].push_back(0);//��ÿһ�к���Ӹ�0�����൱�������һ��0
        }
    }
    //ɾ������
    void RemoveVertex(int index)
    {
        if(index >= index)
        {
            cout << "Vertex doesn't exist" << endl;
        }
        Vertices.erase(Vertices.begin() + index);//ɾ�������б��еĵ�
        AdjMat.erase(AdjMat.begin() + index);//ɾ���ڽӾ���õ��Ӧ��һ��
        for(int i = 0; i < Size(); ++i)//ɾ���ڽӾ�����ÿһ���ж�Ӧ�õ� ��ÿһ��Ԫ�أ��൱��ɾ���˸õ��Ӧ��һ��
        {
            AdjMat[i].erase(AdjMat[i].begin() + index);
        }
    }
    //��ӱ�
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
    //ɾ����
    void RemoveEdge(int i, int j)
    {
        if(i < 0 || j < 0 || i >= Size() || j >= Size() || i == j)
        {
            cout << "Can not add edge" << endl;
        }
        AdjMat[i][j] = 0;
        AdjMat[j][i] = 0;
    }
    //��ӡ�ڽӾ���
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
