#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int EditDistanceDfs(string s, string t, int i, int j)
{
    //i,j表示比较 ? 的前 ? 个字符和 ? 的前 ? 个字符
    
    if(i == 0 && j == 0 )
    {
        return 0;
    }
    if(i == 0)
    {
        return j;//s的前i个元素已经比较完了,但还剩下j,需要在s后执行插入操作
    }
    if(j == 0)
    {
        return i;//t的前j个元素已经比较完了,但还剩下i,需要在s后执行删除操作
    }
    if(s[i-1] == t[j-1])//对应s的第i个元素和t的第j个元素相同,则不需要操作,进入下一轮迭代即可
    {
        return EditDistanceDfs(s, t, i - 1, j - 1);
    }

    int res = min(EditDistanceDfs(s, t, i-1, j), min(EditDistanceDfs(s, t, i, j-1), EditDistanceDfs(s, t, i-1, j-1))) + 1;
/*EditDistanceDfs(s, t, i-1, j)表示删除s第i-1个元素，EditDistanceDfs(s, t, i, j-1)表示在s第i-1个元素后面添加一个t[j]元素，
    EditDistanceDfs(s, t, i-1, j-1)表示将s[i]替换成t[j]
*/
    return res;
}
int main()
{
    string s, t;
    s = "bag";
    t = "pack";
    cout << EditDistanceDfs(s, t, s.length(), t.length());
    return 0;
}