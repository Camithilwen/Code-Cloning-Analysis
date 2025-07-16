#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;

int main() {
    int N, Q; cin >> N >> Q;
    atcoder::fenwick_tree<ll> bit(N+1);
    for (int i=1;i<=N;i++) {
        int a; cin >> a;
        bit.add(i, a);
    }
    for (int q=0; q<Q; q++) {
        int d, l, r; 
		cin >> d >> l >> r;
        if (d == 0) {
            bit.add(l+1, r);
        } else {
            cout << bit.sum(l+1, r+1) << "\n";
        }
    }
}