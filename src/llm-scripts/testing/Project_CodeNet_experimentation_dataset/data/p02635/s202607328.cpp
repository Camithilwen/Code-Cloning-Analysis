
#include <bits/stdc++.h>

using namespace std;

#ifdef Adrian
#include "debug.h"
#else
#define debug(...) 9999
#endif

typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second
#define ii pair<ll,ll>
template <typename G>
struct triple{G F, S, T;};
#define iii triple<int>



int main()
{

#ifdef Adrian
    //freopen("test.txt", "r", stdin);
#else
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#endif


    const ll mod = 998244353;
    string s;
    int h;
    cin>>s>>h;

    int n = 0;
    for(auto &i:s)
        n += (i == '1');

    vector<int> v;
    for(int i=0, j=0; i<s.size(); i=j)
    {
        for(; j<s.size() && s[j] == '1'; j++);
        v.push_back(j - i);
        ++j;
    }

    int m = v.size();
    vector<vector<ll>> cur(n + 1, vector<ll>(n + 1));
    vector<vector<ll>> next(n + 1, vector<ll>(n + 1));
    for(int i=0; i<=n; i++)
        cur[i][0] = 1;

    vector<vector<ll>> ac1(2 * n + 1, vector<ll>(n + 2));
    vector<vector<ll>> ac2(n + 1, vector<ll>(n + 2));

    for(int i=1; i<m; i++)
    {
        for(int j=0; j<=n; j++)
            for(int k=0; k<=n; k++)
            {
                ac1[j + k][j + 1] = cur[j][k];
                ac2[k][j + 1] = cur[j][k];
            }

        for(auto &j:ac1)
            for(int k=1; k<j.size(); k++)
                j[k] = (j[k] + j[k - 1]) % mod;
        for(auto &j:ac2)
            for(int k=1; k<j.size(); k++)
                j[k] = (j[k] + j[k - 1]) % mod;

        for(int j=0; j<=n; j++)
            for(int k=0; k<=n; k++)
            {
                next[j][k] = ac1[j + k][min(n, j + min(v[i], k)) + 1] - ac1[j + k][j];
                next[j][k] += ac2[k][j];

                next[j][k] %= mod;
                if(next[j][k] < 0)
                    next[j][k] += mod;
            }

        swap(next, cur);
    }

    ll ans = 0;
    for(int i=0; i<=min(h, n); i++)
        ans = (ans + cur[0][i]) % mod;

    cout<<ans<<'\n';



    return 0;
}
