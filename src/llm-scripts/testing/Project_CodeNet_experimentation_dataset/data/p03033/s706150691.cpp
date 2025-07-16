#include <iostream>
#include <algorithm>
#include <complex>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
#include <bitset>
#include <cctype>
#include <set>
#include <numeric>
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
inline bool Yes(bool condition){ if(condition) PRINT("Yes"); else PRINT("No"); }
template<class itr> void cins(itr first,itr last){
    for (auto i = first;i != last;i++){
        cin >> (*i);
    }
}
template<class itr> void array_output(itr start,itr goal){
    string ans = "";
    for (auto i = start;i != goal;i++) ans += to_string(*i)+" ";
    if (!ans.empty()) ans.pop_back();
    PRINT(ans);
}
ll gcd(ll a, ll b) {
    return a ? gcd(b%a,a) : b;
}
const ll INF = 1e17;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
const ll MAX = 200005;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,q;
    cin >> n >> q;
    set<ll> num;
    vector<vector<ll>> event;
    ll s,t,x;
    rep(i,n){
        cin >> s >> t >> x;
        vector<ll> a1{s-x,1,x},a2{t-x,-1,x};
        event.push_back(a1);
        event.push_back(a2);
    }
    SORT(event);
    vector<ll> d(q);
    ll index = 0;
    cins(all(d));
    rep(i,2*n){
        while(d[index] < event[i][0] && index < q){
            if (num.empty()) PRINT(-1);
            else PRINT(*num.begin());
            index++;
        }
        if (index == q) break;
        if (event[i][1] == 1) num.insert(event[i][2]);
        if (event[i][1] == -1) num.erase(event[i][2]);
    }
    rep(_,index,q) PRINT(-1);
    return 0;
}
