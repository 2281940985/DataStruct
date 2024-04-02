#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Pair
{
public:
    int Key;
    string Val;
    Pair(int key, string val) : Key(key), Val(val) {}
    ~Pair(){ cout << "Destructor" << endl;}
};
