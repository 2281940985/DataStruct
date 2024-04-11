#include"graph_adjacency_list.cpp"
#include<unordered_set>
#include<queue>
vector<Vertex *> GraphBfs(GraphAdjList &graph_adj_list, Vertex *startVet)
{
    vector<Vertex *> ret;//用来返回遍历后的数组
    unordered_set<Vertex *> Visited = {startVet};//用来记录已被遍历的节点
    queue<Vertex*> que;//先入先出对应遍历的由远及近
    que.push(startVet);
    while (!que.empty())
    {
        Vertex *vet = que.front();
        que.pop();
        ret.push_back(vet);
        //遍历相邻的节点，AdjList中的当前key也是其他key的value,并且当前key的value不可能包含自身
        //因为图一定是连通的，所以不停的遍历相邻的点一定能全部遍历完
        for(auto &adjlist : graph_adj_list.AdjList[vet])
        {
            if(!Visited.count(adjlist))
            {
                que.push(adjlist);//入队未被访问的相邻节点
                Visited.emplace(adjlist);//更新已经被访问的节点
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
    vector<Vertex *> Ret = GraphBfs(graph,v[5]);
    for(auto &val : Ret)
    {
        cout << val ->Val << "  ";
    }
    cout << endl;
    graph.Print();
}
