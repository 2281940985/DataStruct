#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int EditDistanceDfs(string s, string t, int i, int j)
{
    //i,j��ʾ�Ƚ� ? ��ǰ ? ���ַ��� ? ��ǰ ? ���ַ�
    
    if(i == 0 && j == 0 )
    {
        return 0;
    }
    if(i == 0)
    {
        return j;//s��ǰi��Ԫ���Ѿ��Ƚ�����,����ʣ��j,��Ҫ��s��ִ�в������
    }
    if(j == 0)
    {
        return i;//t��ǰj��Ԫ���Ѿ��Ƚ�����,����ʣ��i,��Ҫ��s��ִ��ɾ������
    }
    if(s[i-1] == t[j-1])//��Ӧs�ĵ�i��Ԫ�غ�t�ĵ�j��Ԫ����ͬ,����Ҫ����,������һ�ֵ�������
    {
        return EditDistanceDfs(s, t, i - 1, j - 1);
    }

    int res = min(EditDistanceDfs(s, t, i-1, j), min(EditDistanceDfs(s, t, i, j-1), EditDistanceDfs(s, t, i-1, j-1))) + 1;
/*EditDistanceDfs(s, t, i-1, j)��ʾɾ��s��i-1��Ԫ�أ�EditDistanceDfs(s, t, i, j-1)��ʾ��s��i-1��Ԫ�غ������һ��t[j]Ԫ�أ�
    EditDistanceDfs(s, t, i-1, j-1)��ʾ��s[i]�滻��t[j]
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