#include"hash.hpp"

class HashMapOpenAddressing
{
private:
    int Size;
    int Capacity;
    const double LoadThres = 2.0/3.0;
    const int ExtendRatio = 2;
    vector<Pair *> Buckets;
    Pair *TOMBSTONE = new Pair(-1, "-1");//ɾ����ǣ�
    //ɾ��Buckets��Ԫ�غ󣬲���ֱ����ΪNULL�������Ӱ���̵Ĳ��ң�
public:
    HashMapOpenAddressing() : Size(0), Capacity(4), Buckets(Capacity, nullptr) {}//��ʼ��Buckets����СΪCapacity,Ԫ��Ϊnullptr
    ~HashMapOpenAddressing() 
    {
        for(auto pair : Buckets)
        {
            if(pair != nullptr && pair != TOMBSTONE)
            {
                delete pair;//ÿһ��pair��Ϊ���������ptr,ָ��ͬ������
            }
            
        }
        delete TOMBSTONE;//�ڶ��ϴ�����һ��ָ�룬�ͷ��ڴ�ֻ��Ҫɾ��һ�ξ���
        //��ʹ��Buckets���кܶ�TOMBSTONE,�����Ƕ���ָ�룬ָ����ڴ���Ƕ��ϵ�ͬһ���������ֻ��Ҫdeleteһ�ξ���
    }
    //Hash Function
    int HashFunc(int key)
    {
        return key % Capacity;
    }

    int addHash(string Val) 
    {
        long long hash = 0;
        const int MODULUS = 1000000007;
        for (unsigned char c : Val)
        {
            hash = (hash + (int)c) % MODULUS;
        }
        return (int)hash;
    }
    //Compute Load factor
    double LoadFactor()
    {
        return (double) Size/Capacity;
    }
    int FindBucket(int Key)
    {
        int index = HashFunc(Key);
        int FirstTombstone = -1;
        while(Buckets[index])//����̽�⣬�������յ�Buckeetsʱ����
        {//˵�������˵�һ��ɾ����ǣ���������ֵ
            if(FirstTombstone == -1 && Buckets[index] == TOMBSTONE)
            {
                FirstTombstone = index;
            }
            if(Buckets[index] ->Key == Key)//�ҵ���Ŀ��Ͱ��
            {
                if(FirstTombstone != -1)//˵����Ŀ��Ͱ֮ǰ���Ѿ���ɾ������ˣ�Ҫ����Ŀ��Ͱǰ����ɾ����Ǵ���������ڲ��ң����ȱ
                {
                    Buckets[FirstTombstone] = Buckets[index];
                    Buckets[index] = TOMBSTONE;
                    return FirstTombstone;//��ʱĿ��Ͱ������ΪFirstTombstone��������
                }
                return index;//Ŀ��Ͱ֮ǰ��û��ɾ����ǣ�ֱ�ӷ���index����
            }
            index = (index + 1) % Capacity;//����Hashfunc()�õ���index����Ŀ������,Ӧ�ü�����������
            //Buckets�Ĵ�С������Capacity,(index+1)�����л�����һ��Ͱ,�ظ��ù��̣�%Capacity��Ϊ�˲�ͣ��+1�󲻻ᳬ��Capacity,����Bucketsĩβ��,�ֻ��ͷ��ʼ����ִ��ѭ��
        }
        return FirstTombstone == -1 ? index : FirstTombstone;

    }
    //Hash Searching
    string HashGet(int Key)
    {
        int index = FindBucket(Key);
        if(Buckets[index] != nullptr && Buckets[index] != TOMBSTONE)
        {
            return Buckets[index] ->Val;
        }
        return " Value is null";
        
    }
    //Hash Puting
    void HashPut(int Key, string Val)
    {
        if(LoadFactor() > LoadThres)
        {
            HashExtend();
        }
        int index = FindBucket(Key);
        //key-value  already exist
        if(Buckets[index] != nullptr && Buckets[index] != TOMBSTONE)
        {
            Buckets[index] ->Val = Val;
            return;
        }
        //key-value dosen't exist
        Buckets[index] = new Pair (Key, Val);
        Size++;
    }
    //Hash deleting
    void HashRemoving(int Key)
    {
        int index = FindBucket(Key);
        if(Buckets[index] != nullptr && Buckets[index] != TOMBSTONE)
        {
            delete Buckets[index];
            Buckets[index] = TOMBSTONE;
            Size--;
            return;
        }
    }
    //Extend Hash table
    void HashExtend()
    {
        vector<Pair *> tmp = Buckets;
        Capacity *= ExtendRatio;
        Buckets = vector<Pair *>(Capacity, nullptr);
        Size = 0;
        for(auto pair : tmp)//Ϊʲô������ֱ�Ӹ�ֵ��Buckets = tmp
        //A:��Ϊִ�����ݺ�Capacity�Ѿ��ı䣬HashFunc()Ҳ�����˸ı䣬֮ǰ��Ͱ��Ų��ܼ������ã����Ҫ���½�tmp�е�Ԫ��һ��һ��ѹ�����ݺ��Buckets�С�
        {
            if(pair != nullptr && pair != TOMBSTONE)
            {
                HashPut(pair ->Key, pair ->Val);
                delete pair;
            }
        }

    }
    void HashPrinting()
    {
        cout << " Key -----------> Val " << endl;
        for(auto pair : Buckets)
        {
            if(pair != nullptr && pair != TOMBSTONE)
            {
                cout << pair ->Key << "---->" << pair ->Val << endl;
            }
            
        }
    }

};

int main()
{
    HashMapOpenAddressing map;
    map.HashPut(12836, "zd");
    map.HashPut(15937, "za");
    map.HashPut(16750, "zs");
    map.HashPut(13276, "zf");
    map.HashPut(10583, "zg");
    
    cout << map.HashGet(12839) << endl;
    map.HashRemoving(10583);
    map.HashPut(13145, "InitialZ");
    map.HashPut( map.addHash("InitialZ is a student"), "InitialZ is a student");
    map.HashPrinting();
    return 0;
}

