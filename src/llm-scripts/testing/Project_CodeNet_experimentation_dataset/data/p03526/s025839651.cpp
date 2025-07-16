#include "bits/stdc++.h"
using namespace std;
#define fi first
#define se second
#define ll long long
#define dbg(v) cerr<<#v<<" = "<<v<<'\n'
#define vi vector<int>
#define vl vector <ll>
#define pii pair<int,int>
#define mp make_pair
#define db long double
#define pb push_back
#define all(s) s.begin(),s.end()
template < class T > T smin(T &a,T b) {if (a > b) a = b;return a;}
template < class T > T smax(T &a,T b) {if (a < b) a = b;return a;}
ll dp[5555];
int main(void)
{
    int n;
    cin>>n;
    vector < pii > s(n);
    for (auto &it : s)
        cin>>it.fi>>it.se;
    sort(all(s),[&](pii x,pii y)
         {
            return (x.fi + x.se) < (y.fi + y.se);
         });
    for (int i = 1;i <= n;++i)
        dp[i] = 1e18;
    dp[0] = 0;
    for (auto it : s)
        for (int i = n;i;--i)
            if (dp[i - 1] <= it.fi)
                smin(dp[i],dp[i - 1] + it.se);
    int ans = 0;
    for (int i = 0;i <= n;++i)
        if (dp[i] < 1e18)
            ans = i;
    cout << ans << '\n';
    return 0;
}
