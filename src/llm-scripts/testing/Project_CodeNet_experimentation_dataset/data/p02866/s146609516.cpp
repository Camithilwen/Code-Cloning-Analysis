#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */
const int mod = 998244353;
long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


int main() {
    int N; cin >> N;
    map<int, ll> m;
    int D[N]; rep(i, N) cin >> D[i], m[D[i]]++;
    bool ok = true;
    if(D[0] != 0) ok = false;
    if(m[0] != 1) ok = false;
    ll ans = 1;
    ll prev = m[0], prev_num = -1;
    for(auto itr = m.begin(); itr != m.end(); ++itr) {
        if(prev_num != itr -> first - 1) ok = false;
        ans = (ans * modpow(prev, itr -> second)) % mod;
        prev = itr -> second;
        prev_num = itr -> first;
    }
    cout << ((ok) ? ans : 0) << endl;
}
