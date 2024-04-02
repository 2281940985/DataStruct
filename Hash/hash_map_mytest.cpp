#include"hash.hpp"
class ArryHashMap
{
private:
    vector<Pair *> Buckets;
public:
    ArryHashMap()
    {
        Buckets = vector<Pair *>(100) ;//初始化数组大小为100
    }
    ~ArryHashMap()
    {
        cout << "Destucted" << endl;
    }
    //Hash function
    int HashFunc(int key)
    {
        return key % 100;
    }
    //Hash Searching
    string HashSearch(int key)
    {
        if(Buckets[HashFunc(key)] == NULL)
        {
            return "NULL";
        }
        return Buckets[HashFunc(key)] ->Val; 
    }
    //Hash Puting
    void HashPut(int key, string val)
    {
        int index = HashFunc(key);
        //Pair *pair = vector<Pair>(1);
        Pair *pair = new Pair(key, val);
        Buckets[index] = pair;
    }
    //Hash Removing
    void HashRemove(int key)
    {
        int index = HashFunc(key);
        delete Buckets[index];
        Buckets[index] = NULL;
    }
    //Geting all key-val sets---Buckets
   vector<Pair *>PairSets()
   {
        vector<Pair *> pairsets;
        for(int i = 0; i < Buckets.size(); ++i)
        {
            if(Buckets[i])
            {
                pairsets.push_back(Buckets[i]);
            }
        }
        return pairsets;
   }
   //Geting all keys
   vector<int> KeySets()
   {
        vector<int> keysets;
        for(int i = 0; i < Buckets.size(); ++i)
        {
            if(Buckets[i])
            {
                keysets.push_back(Buckets[i] ->Key);
            }
        }
        return keysets;
   }
   //Geting all values
   vector<string> ValueSets()
   {
        vector<string> valuesets;
        for(int i = 0; i < Buckets.size(); ++i)
        {
            if(Buckets[i])
            {
                valuesets.push_back(Buckets[i] ->Val);
            }
        }
        return valuesets;
   }
   //Print Hash Table
   void PrintHashTable()
   {
        for(int i = 0; i < PairSets().size(); ++i)
        {
            cout << "Key: " << PairSets()[i] ->Key << "--->" << "Value: " << PairSets()[i] ->Val << endl;
        }
        
   }
    
};
int main()
{
    ArryHashMap map;
    map.HashPut(12836, "zd");
    map.HashPut(15937, "za");
    map.HashPut(16750, "zs");
    map.HashPut(13276, "zf");
    map.HashPut(10583, "zg");
    cout << "Key -> Value" << endl;
    map.PrintHashTable();
    return 0;
}
