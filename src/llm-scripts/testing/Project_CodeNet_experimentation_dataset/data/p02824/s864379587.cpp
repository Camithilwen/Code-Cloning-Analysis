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
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
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
const ll INF = 1e10;
const ll MOD = 100000000;
const ll MOD2 = 998244353;
typedef pair<ll,ll> P;
const ll MAX = 100;
constexpr ll nx[8] = {1,0,-1,0,-1,-1,1,1};
constexpr ll ny[8] = {0,1,0,-1,-1,1,-1,1};
typedef pair<ll,ll> P;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,v,p;
    cin >> n >> m >> v >> p;
    vector<ll> a(n);
    cins(all(a));
    SORT(a);
    v--;
    ll l = -1,r = n-1;
    while(r-l > 1){
        vector<ll> b = a;
        ll mid = (l+r)/2;
        b[mid] += m;
        ll cnt = 0,same = 0,big = 0;
        vector<ll> mod;
        rep(i,n){
            if (i == mid) continue;
            if (b[mid] > b[i]){
                if (b[mid]-b[i] >= m) cnt += m;
                else{
                    cnt += b[mid]-b[i];
                    mod.push_back(m-(b[mid]-b[i]));
                }
            }
            else if (b[mid] == b[i]){
                same++;
            }
            else{
                big++;
                cnt += m;
            }
        }
        RSORT(mod);
        if (cnt >= v*m){
            //NONE
        }
        else if (cnt+same*m >= v*m){
            ll s = v*m-cnt;
            big += (s%m ? s/m+1 : s/m);
        }
        else{
            ll s = v*m-(cnt+same*m);
            big += same;
            ll i = 0;
            while(s > 0){
                s -= mod[i];
                big++;
                i++;
            }
        }
        if (big < p) r = mid;
        else l = mid;
        //PRINT(a[mid] << " " << cnt << " " << same << " " << big);
    }
    //PRINT(a[r]);
    PRINT(a.end()-lower_bound(all(a),a[r]));
}
