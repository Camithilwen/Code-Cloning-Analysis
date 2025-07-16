#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int n; cin >> n;
    vector<int> b(n), dp(n+1, -1);
    rep(i, n) cin >> b[i];
    rep(i, n){
        int p = lower_bound(dp.rbegin(), dp.rend(), b[i]) - dp.rbegin() - 1;
        p = n - p;
        // pr(p);
        if(p==-1) dp[0] = b[i];
        else dp[p] = b[i];
        // prvec(dp);
    }

    rep(i, n+1){
        if(dp[i]==-1) {pr(i); break;}
    }

    vector<int> a = {8,5,2};
    // pr(3 - 1 - ((upper_bound(a.rbegin(), a.rend(), 1) - a.rbegin()) - 1));
    return 0;}