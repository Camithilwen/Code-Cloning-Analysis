#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    ll N; cin >> N;
    ll a = N/15;
    ll b = N/3;
    ll c = N/5;
    cout << N*(N+1)/2 + 15*a*(a+1)/2 - 3*b*(b+1)/2 - 5*c*(c+1)/2 << endl;
    return 0;
}