#include <bits/stdc++.h>
using namespace std;
#define ll long long
//#define fr(i,j,k) for(int i=j;i<k;i++)
//#define f(n) fr(i,0,n)
//#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const ll mod = 1e11 + 7;
const int maxn = 2e5+5;
#include<atcoder/all>
using namespace atcoder;
void solve() {
    int n, m;
    cin >> n >> m;
    fenwick_tree<ll>b(n);
    for(int i = 0 ; i < n ; i++) {
        ll x;
        cin >> x;
        b.add(i,x);
    }
    while (m--) {
        int op;
        cin >> op;
        if (!op) {
            int p, x;
            cin >> p >> x;
            b.add(p,x);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << b.sum(l, r) << '\n';
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        solve();
    }
    
}
