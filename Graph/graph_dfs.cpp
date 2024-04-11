#include"graph_adjacency_list.cpp"
#include<unordered_set>
//������ȱ�����������
void dfs(GraphAdjList &graph_adj_list, unordered_set<Vertex *> &visited, 
            vector<Vertex *> &ret, Vertex *startVet)
    {//Ҫ�ݹ�ĺ��������ں����ڴ�������ı�������Ϊÿһ�ε�������Ҫ��������Ŀռ�洢��Щ�����Ҳ����ͷ��ڴ棬���Ա���������ʹ�ô���
        ret.push_back(startVet);
        visited.emplace(startVet);
        for(auto &adj : graph_adj_list.AdjList[startVet])
        {
            if(!visited.count(adj))
            {
                dfs(graph_adj_list, visited, ret, adj);
            }
            
        }
    }
vector<Vertex *> GraphDfs(GraphAdjList &graph_adj_list, Vertex * startVet)
{
    vector<Vertex *> ret;
    unordered_set<Vertex *> visited;
    dfs(graph_adj_list, visited, ret, startVet);
    return ret;
}
int main()
{
    vector<Vertex *> v = ValsToVets(vector<int>{1,3,2,5,4});
    vector<vector<Vertex *>> edges = {{v[0], v[1]}, {v[0], v[3]}, {v[1], v[2]},
                                      {v[2], v[3]}, {v[2], v[4]}, {v[3], v[4]}};
    GraphAdjList graph(edges);
    graph.Print();
    //��ӱ�
    graph.AddEdge(v[0],v[2]);
    cout << "\n Add edge 1-2:" << endl;
    graph.Print();
    //ɾ����
    cout << "Remove edge 1-3: " << endl;
    graph.RemoveEdge(v[0],v[1]);
    cout << "Remove edge 1-3: " << endl;
    graph.Print();
    //��Ӷ���
    cout << "Add new vertex 6:" << endl;
    v.push_back(new Vertex(6));
    graph.AddEdge(v[0],v[5]);
    vector<Vertex *> Ret = GraphDfs(graph,v[5]);
    for(auto &val : Ret)
    {
        cout << val ->Val << "  ";
    }
    cout << endl;
    graph.Print();
}