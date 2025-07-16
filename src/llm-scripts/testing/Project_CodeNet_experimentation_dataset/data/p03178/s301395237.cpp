#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvl vector<vector<long long>>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define vpli vector<pair<long long, int>>
#define vs vector<string>
#define deb(x) cout << x << endl;
#define all(x) x.begin(), x.end()
vector<vvi> dp;
int M = 1e9 + 7;
vi k;
int d;
void modadd(int &a, int b)
{
    a = (a + b) % M;
    if(a<0)
        a+= M;
}

int helper(int pos, bool full, int sum)
{
    if (pos == k.size())
        return (sum == 0);
    if (dp[pos][full][sum] != -1)
        return dp[pos][full][sum];
    int limit = (full ? (k[pos]) : (9));
    int ans = 0;
    for (int i = 0; i <= limit; i++)
    {
        modadd(ans, helper(pos + 1, full && (i == limit), (sum+i)%d ) );
    }
    dp[pos][full][sum] = ans;
    return ans;
}

void solve()
{
    string s;
    cin >> s >> d;
    k.resize(s.size());
    for (int i = 0; i < s.size(); i++)
    {
        k[i] = s[i] - '0';
    }
    dp.resize(s.size());
    for (vvi &t : dp)
    {
        t.resize(2);
        for (vi &u : t)
        {
            u.resize(d+1);
            for (int &x : u)
                x = -1;
        }
    }
    cout << ((helper(0, 1, 0)-1+M)%M)<<endl;
}

int main()
{
    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}