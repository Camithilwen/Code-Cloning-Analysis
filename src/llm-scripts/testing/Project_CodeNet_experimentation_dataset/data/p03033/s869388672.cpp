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

struct koji {
    int t, x;
    int flag;

    bool operator<(const koji& other) const {
        if (t < other.t) return true;
        else return false;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> S(N), T(N), X(N), D(Q);
    vector<koji> kojis(2*N);
    REP(i, N) {
        cin >> S[i] >> T[i] >> X[i];
        S[i] -= X[i];
        T[i] -= X[i];
        kojis[2*i].t = S[i];
        kojis[2*i+1].t = T[i];
        kojis[2*i].x = X[i];
        kojis[2*i+1].x = X[i];
        kojis[2*i].flag = 1;
        kojis[2*i+1].flag = -1;
    }
    sort(ALL(kojis));
    REP(i, Q) cin >> D[i];

    int k = 0;
    multiset<int> events;
    REP(i, Q) {
        

        while(k < kojis.size() && kojis[k].t <= D[i]) {
            if(kojis[k].flag == 1) events.insert(kojis[k].x);
            else events.erase(events.find(kojis[k].x));
            k++;
        }

        if(events.empty()) {
            cout << -1 << endl;
        } else {
            cout << *events.begin() << endl;
        }
    }

    return 0;
}