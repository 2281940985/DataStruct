#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;
//顶点类
struct Vertex
{
    int Val;
    Vertex(int val) : Val(val) {}
};
/* 输入值列表 vals ，返回顶点列表 vets */
vector<Vertex *> ValsToVets(vector<int> vals)
{
    vector<Vertex *> Vets;
    for(auto v : vals)
    {
        Vets.push_back(new Vertex(v));
    }
    return Vets;
}
/* 输入顶点列表 vets ，返回值列表 vals */ //这里没用到
vector<int> VetsToVals(vector<Vertex *> Vets)
{
    vector<int> Vals;
    for(auto vet : Vets)
    {
        Vals.push_back(vet ->Val);
    }
    return Vals;
}
class GraphAdjList
{
public:
    unordered_map<Vertex *,vector<Vertex *>> AdjList;//它的元素为adj,adj.first是key类型为Vertex*; adj.second是value,类型为vector<Vertex*>
    GraphAdjList(const vector<vector<Vertex *>> &edges)//传入顶点之间的关系，一条边只包含两个顶点，所以第二个vector只有两个元素
    {
        for(auto &edge : edges)
        {
            AddVertex(edge[0]);
            AddVertex(edge[1]);//把一条边的两个顶点添加进去
            AddEdge(edge[0],edge[1]);
        }
    //这里有个问题：为什么自始至终用的都是Vertex*而不用Vertex？
    //A:因为在刚初始化类时，要传入顶点之间边的关系，而顶点都是用int表示,我们无法将int类型的元素转换成Vertex，但是Vertex类中有Val可以给我们传递进int类型元素
    //所以利用new Vertex(int a),创建Vertex*指针，该指针指向Vertex,且该Vertex中的Val等于顶点的值
    }
    ~GraphAdjList(){}
    int Size()
    {
        return AdjList.size();
    }
    //添加顶点
    void AddVertex(Vertex *vet)
    {
        if(AdjList.count(vet))
        {
            return;//找到了顶点，说明不需要添加
        }
        AdjList[vet] = vector<Vertex *>();//传入一组k-v,key为AdjList[vet]，value为vector<Vertex *>()因为还未添加边，所以创建的vector<Vertex*>为空
    }
    //删除顶点
    void RemoveVertex(Vertex *vet)
    {
        if(!AdjList.count(vet))
        {
            cout << "Vertex does not exist" << endl;
        }
        AdjList.erase(vet);//先删除AdjList中的key
        for(auto &adj : AdjList)
        {
            for(int i = 0; i < adj.second.size(); ++i)//adj.second是adj的value
            {
                if(adj.second[i] == vet)
                {   //不能写adj.second.erase(vet),vector中不能删除指定元素，只能删除指定位置的元素，所以要先遍历找到相对begin()的位置后在执行删除
                    adj.second.erase(adj.second.begin() + i);
                    break;//双层循环，break只会打破最近的循环
                }
            }
        }
    }
    //添加边
    void AddEdge(Vertex *vet1, Vertex *vet2)
    {
        if(!AdjList.count(vet1) || !AdjList.count(vet2) || vet1 == vet2)
        {
            cout << "Vertex does not exist" << endl;
        }
        AdjList[vet1].push_back(vet2);//vet1是key,AdjList[vet1]是value
        AdjList[vet2].push_back(vet1);
    }
    //删除边
    void RemoveEdge(Vertex *vet1, Vertex *vet2)
    {
        if(!AdjList.count(vet1) || !AdjList.count(vet2) || vet1 == vet2)
        {
            cout << "Vertex does not exist" << endl;
        }
        for(auto &adj : AdjList)
        {
            if(adj.first == vet1)//vet1中的value要添加vet2，同理vet2中的value也要添加vet1
            {
                for(int i = 0; i < adj.second.size(); ++i)
                {
                    if(adj.second[i] == vet2)
                    {
                        adj.second.erase(adj.second.begin() + i);
                        break;
                    }
                }
            }
            else if(adj.first == vet2)//这里可以写成一个函数
            {
                for(int i = 0; i < adj.second.size(); ++i)
                {
                    if(adj.second[i] == vet1)
                    {
                        adj.second.erase(adj.second.begin() + i);
                        break;
                    }
                }
            }
        }
    }

    //打印邻接表
    void Print()
    {
        cout << "Adjacency List :" << endl;
        for(auto &adj : AdjList)
        {//无论是key还是value存储的元素都是Vertex*,我们要打印的是Val,别忘了指针
            cout << adj.first ->Val << " : " ;
            for(int i = 0; i < adj.second.size(); ++i)
            {
                cout << adj.second[i] ->Val << "   ";
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<Vertex *> v = ValsToVets(vector<int>{1,3,2,5,4});
    vector<vector<Vertex *>> edges = {{v[0], v[1]}, {v[0], v[3]}, {v[1], v[2]},
                                      {v[2], v[3]}, {v[2], v[4]}, {v[3], v[4]}};
    GraphAdjList graph(edges);
    graph.Print();
    //添加边
    graph.AddEdge(v[0],v[2]);
    cout << "\n Add edge 1-2:" << endl;
    graph.Print();
    //删除边
    cout << "Remove edge 1-3: " << endl;
    graph.RemoveEdge(v[0],v[1]);
    cout << "Remove edge 1-3: " << endl;
    graph.Print();
    //添加顶点
    cout << "Add new vertex 6:" << endl;
    v.push_back(new Vertex(6));
    graph.AddEdge(v[0],v[5]);
    graph.Print();
    //释放内存
    for(auto &vet : v)
    {
        delete vet;
    }
    return 0;
    

}









