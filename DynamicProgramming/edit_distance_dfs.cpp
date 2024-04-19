#include<iostream>
#include<vector>
#include<string>
using namespace std;

int EditDistanceDfs(string s, string t, int i, int j)//i,j��ʾ�Ƚ�s��i��֮ǰ��Ԫ����t��j��֮ǰ��Ԫ��
{

    if(i == s.length() && j == t.length())
        return 0;//��ʾs,��t���Ƚ�����,����Ҫ���޸��ˣ�����0����
    if(i == s.length())
        return t.length() - j;//��ʾs�Ƚ����ˣ�t��û�бȽ��꣬��Ҫ��s�������Ԫ��
    if(j == t.length())
        return s.length() - i;//��ʾt�Ƚ����ˣ�s��û�бȽ��꣬��Ҫ��s����ɾ��Ԫ��
    
    if(s[i] == t[j])
        return EditDistanceDfs(s, t, i+1, j+1);//s��i��֮ǰ��t��j��֮ǰ��Ԫ����ͬ������Ҫ�޸ģ�����������
    
    int ans = 1 + min(EditDistanceDfs(s, t, i+1, j), min(EditDistanceDfs(s, t, i, j+1), EditDistanceDfs(s, t, i+1, j+1)));
    /*EditDistanceDfs(s, t, i+1, j)��ʾɾ��s��i��Ԫ�أ�EditDistanceDfs(s, t, i, j+1)��ʾ��s��i��Ԫ�غ������һ��t[j]Ԫ�أ�
    EditDistanceDfs(s, t, i+1, j+1)��ʾ��s[i]�滻��t[j]
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