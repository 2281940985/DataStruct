#include"graph_adjacency_list.cpp"
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
    v.push_back(new Vertex(6));//在图中添加顶点
    graph.AddVertex(v[5]);//在邻接表中添加顶点
    graph.AddEdge(v[0],v[5]);
    graph.Print();
    //释放内存
    for(auto &vet : v)
    {
        delete vet;
    }
    return 0;
    

}