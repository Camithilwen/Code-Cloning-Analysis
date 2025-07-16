#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e16
typedef long long ll;


int main() {
    ll N;
    cin >> N;
    ll m = INF;
    REP(i,5){
        ll t;
        cin >> t;
        m = min(m,t);
    }

    cout << 5 + (N-1)/m << endl;


    return 0;
}