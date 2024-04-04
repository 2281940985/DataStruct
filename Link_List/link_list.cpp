#include<iostream>
#include<vector>

using namespace std;
template<typename T>
class ArryQueen
{
private:
    int Size;
    int Capacity;
    const double LoadThres = 2.0/3.0;
    const int ExtendRatio = 2;
    vector<T> Nums;
    int Front;
public:
    ArryQueen() : Size(0), Capacity(5), Nums(Capacity), Front(0) {}
    ~ArryQueen(){}
    int QueenCapacity();
    int QueenSize();
    bool IsEmpty();
    double LoadFactor();
    void ArryQueenPush(T val);
    T ArryQueenPop();
    T ArryQueenPeek();
    void ArryQueenPrint();
};
template<typename T>
int ArryQueen<T> ::QueenCapacity()
{
    return Capacity;
}
template<typename T>
int ArryQueen<T> :: QueenSize()
{
    return Size;
}
template<typename T>
bool ArryQueen<T> ::IsEmpty()
{
    return Size == 0;
}
template<typename T>
double ArryQueen<T> ::LoadFactor()
{
    return (double) Size/Capacity;
}
template<typename T>
void ArryQueen<T> ::ArryQueenPush(T val)
{
    if(LoadFactor() > LoadThres)
    {
        vector<T> tmp = Nums;
        Capacity *= ExtendRatio;
        Nums.clear();//全部清空,Nums中一个元素都没
        Nums = vector<T>(Capacity);//重新分配大小，此时Nums大小为Capaciaze
        for(int i = 0; i < tmp.size(); ++i)
        {
            Nums[i] = tmp[i];
        }
    }
    if(Size == 0)
    {
        Nums[Front] = val;
    }else
    {
        Nums[Front + Size] = val;
    }
    Size++;
        
}
template<typename T>
T ArryQueen<T> ::ArryQueenPop()
{
    T tmp = Nums[Front];
    Front ++;
    Size --;
    return tmp;
}
template<typename T>
T ArryQueen<T> ::ArryQueenPeek()
{
    return Nums[Front];
}
template<typename T>
void ArryQueen<T> ::ArryQueenPrint()
{
    int i = Front;
    while(Nums[i])//采用For循环无法遍历得到完整的队列元素，因为每次POP后，弹出的是队首元素，但Size-1了
    {
        cout << Nums[i] << "  ";
        i ++;
    }
    cout << endl;
}

int main()
{
    ArryQueen<int> aq;
    aq.ArryQueenPush(1);
    aq.ArryQueenPush(2);
    aq.ArryQueenPush(3);
    aq.ArryQueenPush(4);
    aq.ArryQueenPush(5);
    aq.ArryQueenPush(6);
    aq.ArryQueenPrint();
    cout << aq.QueenCapacity() << endl;
    return 0;
}

