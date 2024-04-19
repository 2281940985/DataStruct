#include <iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int EditDistanceDPComp(string s, string t)
{
    vector<int> dp(t.length()+1, 0);
    //状态转移：首行
    for(int j = 1; j <= t.length(); j++)
    {
        dp[j] = j;
    }
    //状态转移：其余行
    for(int i = 1; i <= s.length(); i++)
    {
        int left_up = dp[0];
        for(int j = 1; j <= t.length(); j++)
        {
            int tmp = dp[j];
            if(s[i-1] == t[j-1])
            {
                dp[j] = left_up;
            }
            else
            {
                dp[j] = min(left_up, min(dp[j], dp[j-1])) + 1;
            }

            left_up = tmp; //更新为下一轮的dp[i-1, j-1]

        }

    }
    return dp[t.length()];
}
int main()
{
    string s = "bag";
    string t = "pack";
    cout << EditDistanceDPComp(s, t) << endl;
    return 0;
}