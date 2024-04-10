#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;
//������
struct Vertex
{
    int Val;
    Vertex(int val) : Val(val) {}
};
/* ����ֵ�б� vals �����ض����б� vets */
vector<Vertex *> ValsToVets(vector<int> vals)
{
    vector<Vertex *> Vets;
    for(auto v : vals)
    {
        Vets.push_back(new Vertex(v));
    }
    return Vets;
}
/* ���붥���б� vets ������ֵ�б� vals */ //����û�õ�
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
    unordered_map<Vertex *,vector<Vertex *>> AdjList;//����Ԫ��Ϊadj,adj.first��key����ΪVertex*; adj.second��value,����Ϊvector<Vertex*>
    GraphAdjList(const vector<vector<Vertex *>> &edges)//���붥��֮��Ĺ�ϵ��һ����ֻ�����������㣬���Եڶ���vectorֻ������Ԫ��
    {
        for(auto &edge : edges)
        {
            AddVertex(edge[0]);
            AddVertex(edge[1]);//��һ���ߵ�����������ӽ�ȥ
            AddEdge(edge[0],edge[1]);
        }
    //�����и����⣺Ϊʲô��ʼ�����õĶ���Vertex*������Vertex��
    //A:��Ϊ�ڸճ�ʼ����ʱ��Ҫ���붥��֮��ߵĹ�ϵ�������㶼����int��ʾ,�����޷���int���͵�Ԫ��ת����Vertex������Vertex������Val���Ը����Ǵ��ݽ�int����Ԫ��
    //��������new Vertex(int a),����Vertex*ָ�룬��ָ��ָ��Vertex,�Ҹ�Vertex�е�Val���ڶ����ֵ
    }
    ~GraphAdjList(){}
    int Size()
    {
        return AdjList.size();
    }
    //��Ӷ���
    void AddVertex(Vertex *vet)
    {
        if(AdjList.count(vet))
        {
            return;//�ҵ��˶��㣬˵������Ҫ���
        }
        AdjList[vet] = vector<Vertex *>();//����һ��k-v,keyΪAdjList[vet]��valueΪvector<Vertex *>()��Ϊ��δ��ӱߣ����Դ�����vector<Vertex*>Ϊ��
    }
    //ɾ������
    void RemoveVertex(Vertex *vet)
    {
        if(!AdjList.count(vet))
        {
            cout << "Vertex does not exist" << endl;
        }
        AdjList.erase(vet);//��ɾ��AdjList�е�key
        for(auto &adj : AdjList)
        {
            for(int i = 0; i < adj.second.size(); ++i)//adj.second��adj��value
            {
                if(adj.second[i] == vet)
                {   //����дadj.second.erase(vet),vector�в���ɾ��ָ��Ԫ�أ�ֻ��ɾ��ָ��λ�õ�Ԫ�أ�����Ҫ�ȱ����ҵ����begin()��λ�ú���ִ��ɾ��
                    adj.second.erase(adj.second.begin() + i);
                    break;//˫��ѭ����breakֻ����������ѭ��
                }
            }
        }
    }
    //��ӱ�
    void AddEdge(Vertex *vet1, Vertex *vet2)
    {
        if(!AdjList.count(vet1) || !AdjList.count(vet2) || vet1 == vet2)
        {
            cout << "Vertex does not exist" << endl;
        }
        AdjList[vet1].push_back(vet2);//vet1��key,AdjList[vet1]��value
        AdjList[vet2].push_back(vet1);
    }
    //ɾ����
    void RemoveEdge(Vertex *vet1, Vertex *vet2)
    {
        if(!AdjList.count(vet1) || !AdjList.count(vet2) || vet1 == vet2)
        {
            cout << "Vertex does not exist" << endl;
        }
        for(auto &adj : AdjList)
        {
            if(adj.first == vet1)//vet1�е�valueҪ���vet2��ͬ��vet2�е�valueҲҪ���vet1
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
            else if(adj.first == vet2)//�������д��һ������
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

    //��ӡ�ڽӱ�
    void Print()
    {
        cout << "Adjacency List :" << endl;
        for(auto &adj : AdjList)
        {//������key����value�洢��Ԫ�ض���Vertex*,����Ҫ��ӡ����Val,������ָ��
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
    graph.Print();
    //�ͷ��ڴ�
    for(auto &vet : v)
    {
        delete vet;
    }
    return 0;
    

}









