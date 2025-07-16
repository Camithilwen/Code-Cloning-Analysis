#include <bits/stdc++.h>
#include <ctime>
#define rep(i,a,b) for(int i =a;i<b;i++)
using namespace std;
typedef unsigned long long ll;
inline int cine() {int a; return scanf("%d", &a) ? a : 1e9;}


void solve() {
    int train, bus, mine = 1e9, sum = 0 ;
    rep(i, 0, 2) {
        cin >> train;
        mine = min(mine, train);
    }
    sum += mine;
    mine = 1e9;
    rep(i, 0, 2) {
        cin >> bus;
        mine = min(mine, bus);
    }
    sum += mine;
    cout << sum;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed :" << 0.1 * clock() / CLOCKS_PER_SEC << "s\n";
#endif
}