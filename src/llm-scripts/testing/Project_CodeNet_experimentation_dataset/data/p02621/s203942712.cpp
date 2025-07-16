#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = pair<int, ii>;
#define vt vector
#define pq priority_queue
#define pb push_back
#define mp make_pair
#define fi first
#define se second
// #define multicase
const int MOD = 1e9 + 7;
const int INF = 2e9;
// const int N = ;

void solve() {
    int T = 1;
  #ifdef multicase
    cin >> T;
  #endif
    for(int tc = 1, n; tc <= T; tc++) {
        cin >> n;
        cout << n + n * n + n * n * n << "\n";
    }
}

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
}