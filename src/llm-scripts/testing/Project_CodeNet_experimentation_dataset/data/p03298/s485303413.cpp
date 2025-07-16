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
const ll MOD = 100000000;
const ll MOD2 = 998244353;
typedef pair<ll,ll> P;
const ll MAX = 200010;
constexpr ll nx[8] = {1,0,-1,0,-1,-1,1,1};
constexpr ll ny[8] = {0,1,0,-1,-1,1,-1,1};
ll n;
string s;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> s;
    map<pair<string,string>,ll> count;
    rep(bit,1<<n){
        string s1,t1;
        rep(i,n){
            if (bit&(1<<i)){
                s1 += s[i+n];
            }
            else{
                t1 += s[i+n];
            }
        }
        reverse(all(t1));
        count[make_pair(t1,s1)]++;
    }
    ll ans = 0;
    rep(bit,1<<n){
        string s1,t1;
        rep(i,n){
            if (bit&(1<<i)){
                s1 += s[i];
            }
            else{
                t1 += s[i];
            }
        }
        reverse(all(t1));
        ans += count[make_pair(s1,t1)];
    }
    PRINT(ans);
}
