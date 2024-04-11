#include"graph_adjacency_list.cpp"
#include<unordered_set>
#include<queue>
vector<Vertex *> GraphBfs(GraphAdjList &graph_adj_list, Vertex *startVet)
{
    vector<Vertex *> ret;//�������ر����������
    unordered_set<Vertex *> Visited = {startVet};//������¼�ѱ������Ľڵ�
    queue<Vertex*> que;//�����ȳ���Ӧ��������Զ����
    que.push(startVet);
    while (!que.empty())
    {
        Vertex *vet = que.front();
        que.pop();
        ret.push_back(vet);
        //�������ڵĽڵ㣬AdjList�еĵ�ǰkeyҲ������key��value,���ҵ�ǰkey��value�����ܰ�������
        //��Ϊͼһ������ͨ�ģ����Բ�ͣ�ı������ڵĵ�һ����ȫ��������
        for(auto &adjlist : graph_adj_list.AdjList[vet])
        {
            if(!Visited.count(adjlist))
            {
                que.push(adjlist);//���δ�����ʵ����ڽڵ�
                Visited.emplace(adjlist);//�����Ѿ������ʵĽڵ�
            }
        }
    }
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
    vector<Vertex *> Ret = GraphBfs(graph,v[5]);
    for(auto &val : Ret)
    {
        cout << val ->Val << "  ";
    }
    cout << endl;
    graph.Print();
}
