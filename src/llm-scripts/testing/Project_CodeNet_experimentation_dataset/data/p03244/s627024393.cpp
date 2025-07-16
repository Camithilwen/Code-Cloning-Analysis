#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n,0);
    rep(i,n)cin >> a[i];
    map<ll,ll> odds;
    for(ll i = 0;i < n;i+=2)odds[a[i]]++;
    pair<ll,ll> of = {0,0};
    pair<ll,ll> os = {0,0};
    for(auto t : odds){
        if(t.second > of.second){
            os = of;
            of = t;
            continue;
        }else if(t.second > os.second){
            os = t;
            continue;
        }
    }

    map<ll,ll> even;
    for(ll i = 1;i < n;i+=2)even[a[i]]++;
    ll e = 0;
    pair<ll,ll> ef = {0,0};
    pair<ll,ll> es = {0,0};
    for(auto t : even){
        if(t.second > ef.second){
            es = ef;
            ef = t;
            continue;
        }else if(t.second > es.second){
            es = t;
            continue;
        }
    }
    if(of.first != ef.first){
        cout << (n/2 - of.second) + (n/2 - ef.second) << "\n";
    }else{
        cout << min((n/2 - os.second)+(n/2 - ef.second) , (n/2 - of.second) + (n/2 - es.second)) << "\n";
    }

    return 0;
}