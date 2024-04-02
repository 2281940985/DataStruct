#include"hash.hpp"
class HashMapChaining
{
private:
    int Size;
    int Capacity;
    double LoadThres;
    int ExtendRatio;
    vector<vector<Pair *>> Buckets;
public:
    HashMapChaining() : Size(0), Capacity(4), LoadThres(2.0/3.0), ExtendRatio(2)
    {
        Buckets.resize(Capacity);
    }
    ~HashMapChaining()
    {
        for(auto &bucket : Buckets)
        {
            for(Pair *pair : bucket)
            {
                delete pair;
            }
        }
    }
    //Hash function
    int HashChainFunc(int Key)
    {
        return Key % Capacity;
    }
    //Get Load factor
    double LoadFactor()
    {
        return (double)Size/(double)Capacity;
    }
    //Hash Searching
    string HashChainGet(int Key)
    {
        int index = HashChainFunc(Key);
        for(auto &bucket : Buckets[index])
        {
            if(bucket->Key == Key)
            {
                return bucket ->Val;
            }
        }
        return "Don't Get";
    }
    //Hash Put
    void HashChainPut(int Key, string Val)
    {
        if(LoadFactor() > LoadThres)
        {
            Extend();
        }
        int index = HashChainFunc(Key);
        for (Pair *pair : Buckets[index])
        {
            if(pair ->Key == Key)
            {
                pair ->Val = Val;
                return;
            }
        }
        Pair *pair = new Pair(Key, Val);
        Buckets[index].push_back(pair);
        Size++;
    }
    //Hash Removing
    void HashChainRemove(int Key)
    {
        int index = HashChainFunc(Key);
        for(auto pair : Buckets[index])
        {
            if(pair ->Key == Key)
            {
                Pair *tmp = pair;
                pair ->Key = 0;
                pair ->Val = "";
                //delete tmp;
                Size--;
                return;
            }
        }
    }
    //Extend hash table;
    void Extend()
    {
        vector<vector<Pair *>> tmp = Buckets;
        Capacity *= ExtendRatio;
        Buckets.clear();
        Buckets.resize(Capacity);
        Size = 0;
        //Wyh can't copy directly? like: Buckets = tmp
        //A: Because hash function changed,must reput every key-value,if not do like this,it can't find key-value.
        for(auto bucket : tmp)
        {
            for(auto pair : bucket)
            {
                HashChainPut(pair ->Key, pair ->Val);
                delete pair;
            }
        }
    }
    //Print hash table
    void PrintHashChaintable()
    {
        for(auto bucket : Buckets)
        {
            for(auto pair : bucket)
            {
                if(pair->Key)
                {
                    cout << "[" << pair->Key << "--->" << pair->Val << "]" << endl;
                }
                
            }
        }
    }


};

int main()
{
    HashMapChaining map;
    map.HashChainPut(12836, "xh");
    map.HashChainPut(15937, "xz");
    map.HashChainPut(16750, "xy");
    map.HashChainPut(13276, "xf");
    map.HashChainPut(10583, "xa");
    map.HashChainPut(13436,"InitialZ");
    cout << "Hash Table is finished" << endl;
    map.PrintHashChaintable();
    cout << map.HashChainGet(15937) << endl;
    cout << map.HashChainGet(13276) << endl;
    map.HashChainRemove(15937);
    cout << "New table" << endl;
    map.PrintHashChaintable();
    return 0;
}