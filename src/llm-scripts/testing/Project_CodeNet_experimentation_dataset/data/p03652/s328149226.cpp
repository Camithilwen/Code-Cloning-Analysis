#include <iostream>
#include <iomanip>
#include <algorithm>
#include <complex>
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <cmath>
#include <bitset>
#include <cctype>
#include <set>
#include <map>
#include <unordered_map>
#include <numeric>
#include <functional>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
inline void Yes(bool condition){ if(condition) PRINT("Yes"); else PRINT("No"); }
template<class itr> void cins(itr first,itr last){
    for (auto i = first;i != last;i++){
        cin >> (*i);
    }
}
template<class itr> void array_output(itr start,itr goal){
    string ans = "",k = " ";
    for (auto i = start;i != goal;i++) ans += to_string(*i)+k;
    if (!ans.empty()) ans.pop_back();
    PRINT(ans);
}
ll gcd(ll a, ll b) {
    return a ? gcd(b%a,a) : b;
}
const ll INF = 1e15;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
typedef pair<ll,ll> P;
typedef pair<double,double> point;
const ll MAX = 200005;
constexpr ll nx[8] = {1,0,-1,0,1,-1,1,-1};
constexpr ll ny[8] = {0,1,0,-1,1,1,-1,-1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vector<bool> a(m,1);
    vector<vector<ll>> sport(n,vector<ll>(m,0));
    rep(i,n){
        rep(j,m){
            cin >> sport[i][j];
            sport[i][j]--;
        }
    }
    ll ans = INF;
    rep(i,m){
        vector<ll> cnt(m,0);
        ll ma = 0;
        rep(j,n){
            rep(k,m){
                ll s = sport[j][k];
                if (a[s]){
                    cnt[s]++;
                    chmax(ma,cnt[s]);
                    break;
                }
            }
        }
        chmin(ans,ma);
        rep(j,m){
            if (cnt[j] == ma){
                a[j] = 0;
                break;
            }
        }
    }
    PRINT(ans);
}
