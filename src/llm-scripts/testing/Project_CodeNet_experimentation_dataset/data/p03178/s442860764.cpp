#include <bits/stdc++.h>

using namespace std;
const int nax = 105;
const int mod = 1e9 + 7;

string s;
int d;

void add_self(int &a, int b)
{
    a += b;

    if(a >= mod)
        a -= mod;
}


int main()
{
    cin >> s;
    cin >> d;

    vector<vector<int>>dp(nax, vector<int>(2));
    int n = s.length();
    dp[0][0] = 1;

    for(int where = 0; where < n; ++where)
    {
        vector<vector<int>>new_dp(nax, vector<int>(2));

        for(int sum = 0; sum < d; ++sum)
            for(int digit = 0; digit < 10; ++digit)
                for(bool is_smaller : {false, true})
                {
                    if(!is_smaller && digit > s[where] - '0')
                        continue;

                    add_self(new_dp[(sum + digit) % d][is_smaller || digit < s[where] - '0'], dp[sum][is_smaller]);
                }

        dp = new_dp;
    }

    int answer = (dp[0][false] + dp[0][true]) % mod;
    --answer;

    if(answer < 0)
        answer += mod;

    cout << answer;

    return 0;
}
