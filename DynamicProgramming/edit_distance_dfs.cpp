#include<iostream>
#include<vector>
#include<string>
using namespace std;

int EditDistanceDfs(string s, string t, int i, int j)//i,j表示比较s第i个之前的元素与t第j个之前的元素
{

    if(i == s.length() && j == t.length())
        return 0;//表示s,与t都比较完了,不需要在修改了，返回0即可
    if(i == s.length())
        return t.length() - j;//表示s比较完了，t还没有比较完，需要在s后面添加元素
    if(j == t.length())
        return s.length() - i;//表示t比较完了，s还没有比较完，需要在s后面删除元素
    
    if(s[i] == t[j])
        return EditDistanceDfs(s, t, i+1, j+1);//s第i个之前与t第j个之前的元素相同，不需要修改，继续向后迭代
    
    int ans = 1 + min(EditDistanceDfs(s, t, i+1, j), min(EditDistanceDfs(s, t, i, j+1), EditDistanceDfs(s, t, i+1, j+1)));
    /*EditDistanceDfs(s, t, i+1, j)表示删除s第i个元素，EditDistanceDfs(s, t, i, j+1)表示在s第i个元素后面添加一个t[j]元素，
    EditDistanceDfs(s, t, i+1, j+1)表示将s[i]替换成t[j]
    */
    return ans;
}
int main()
{
    string s, t;
    cin >> s >> t;
    cout << EditDistanceDfs(s, t, 0, 0);
    return 0;
}