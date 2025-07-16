#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORR(i, m, n) for (int i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin >> n;
    map<ll,ll> mp;
    ll ans=0;
    vector<ll> a(n);
    REP(i,n){
        cin >> a[i];
    }
    sort(ALL(a));
    reverse(ALL(a));
    REP(i,n){
        bool f=false;
        REPR(j,32){
            if((1LL<<j)<=a[i]){
                break;
            }
            if(mp[(1LL<<j)-a[i]]){
                ans++;
                mp[(1LL<<j)-a[i]]--;
                f=true;
                break;
            }
        }
        if(!f){
            mp[a[i]]++;
        }
    }
    cout << ans << endl;
}