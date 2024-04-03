#include"hash.hpp"

class HashMapOpenAddressing
{
private:
    int Size;
    int Capacity;
    const double LoadThres = 2.0/3.0;
    const int ExtendRatio = 2;
    vector<Pair *> Buckets;
    Pair *TOMBSTONE = new Pair(-1, "-1");//删除标记！
    //删除Buckets的元素后，不能直接置为NULL，否则会影响后继的查找，
public:
    HashMapOpenAddressing() : Size(0), Capacity(4), Buckets(Capacity, nullptr) {}//初始化Buckets，大小为Capacity,元素为nullptr
    ~HashMapOpenAddressing() 
    {
        for(auto pair : Buckets)
        {
            if(pair != nullptr && pair != TOMBSTONE)
            {
                delete pair;//每一个pair均为互相独立的ptr,指向不同的区域
            }
            
        }
        delete TOMBSTONE;//在堆上创建的一个指针，释放内存只需要删除一次就行
        //即使在Buckets中有很多TOMBSTONE,但他们都是指针，指向的内存均是堆上的同一块区域，因此只需要delete一次就行
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
        while(Buckets[index])//线性探测，当遇到空的Buckeets时跳出
        {//说明发现了第一个删除标记，保存索引值
            if(FirstTombstone == -1 && Buckets[index] == TOMBSTONE)
            {
                FirstTombstone = index;
            }
            if(Buckets[index] ->Key == Key)//找到了目标桶了
            {
                if(FirstTombstone != -1)//说明在目标桶之前就已经有删除标记了，要将该目标桶前移至删除标记处，方便后期查找，填补空缺
                {
                    Buckets[FirstTombstone] = Buckets[index];
                    Buckets[index] = TOMBSTONE;
                    return FirstTombstone;//此时目标桶的序列为FirstTombstone，返回它
                }
                return index;//目标桶之前并没有删除标记，直接返回index就行
            }
            index = (index + 1) % Capacity;//经过Hashfunc()得到的index不是目标索引,应该继续向下索引
            //Buckets的大小不超过Capacity,(index+1)代表切换到下一个桶,重复该过程，%Capacity是为了不停的+1后不会超出Capacity,到达Buckets末尾后,又会从头开始继续执行循环
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
        for(auto pair : tmp)//为什么不采用直接赋值：Buckets = tmp
        //A:因为执行扩容后，Capacity已经改变，HashFunc()也发生了改变，之前的桶标号不能继续沿用，因此要重新将tmp中的元素一个一个压进扩容后的Buckets中。
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

