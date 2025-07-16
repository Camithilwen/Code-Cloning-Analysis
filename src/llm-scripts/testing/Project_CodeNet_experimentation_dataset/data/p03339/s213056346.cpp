#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;



int main(){FIN

    ll n; string s;
    cin>>n>>s;
    ll ans=mod;
    vll ws(1,0); vll es(1,0);
    ll cnt=0;
    FOR(i,1,n-1){
        
        if(s[i-1]=='W') cnt++;
        ws.push_back(cnt);
    }
    cnt=0;
    FORR(i,n-2,0){
        
        if(s[i+1]=='E') cnt++;
        es.push_back(cnt);
    }
    reverse(ALL(es));
    // REP(i,n){
    //     cout<<ws[i]<<endl;
    // }
    REP(i,n){
        ans = min(ans, es[i]+ws[i]);
    }
    cout<<ans<<endl;
    return 0;
}