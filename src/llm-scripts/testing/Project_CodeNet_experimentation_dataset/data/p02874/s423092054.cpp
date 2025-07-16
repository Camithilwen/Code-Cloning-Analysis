#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

ll l_max = 0, r_min = 1e9+5;

struct problem {
    ll l;
    ll r;
    ll a;
    ll b;

    bool operator<(const problem& other) const {
        if (a < other.a ) return true;
        else if(a > other.a ) return false;
        else return b > other.b;
    }
};

int main() {
    int N, l_arg, r_arg;
    cin >> N;
    
    vector<ll> L(N), R(N);
    vector<problem> problems(N);
    REP(i, N) {
        ll l, r;
        cin >> l >> r;
        L[i] = l;
        R[i] = r+1;
        if(l_max < l) {
            l_max = l;
            l_arg = i;
        }
        if(r_min > r + 1) {
            r_min = r + 1;
            r_arg = i;
        }
    }

    ll length_max = 0;
    REP(i, N) {
        problems[i].l = L[i];
        problems[i].r = R[i];
        problems[i].a = max(R[i] - l_max, ll(0));
        problems[i].b = max(r_min - L[i], ll(0));
        if(R[i] - L[i] > length_max) length_max = R[i] - L[i];
    }

    sort(ALL(problems));

    set<ll> tset;
    ll ans = 0, min1, min2;
    min1 = problems[0].a;
    min2 = 0;
    ans = min1 + min2;

    FOR(i, 1, N-1) {
        min1 = problems[i].a;
        tset.insert(problems[i-1].b);
        min2 = *tset.begin();
        if(ans < min1 + min2) ans = min1 + min2;
    }

    tset.insert(problems[N-1].b);
    if(ans < *tset.begin()) {
        ans = *tset.begin();
    }

    if(ans < length_max + max(min(R[l_arg], R[r_arg]) - max(L[l_arg], L[r_arg]), ll(0)))
        ans = length_max + max(min(R[l_arg], R[r_arg]) - max(L[l_arg], L[r_arg]), ll(0));

    cout << ans << endl;
    return 0;
}