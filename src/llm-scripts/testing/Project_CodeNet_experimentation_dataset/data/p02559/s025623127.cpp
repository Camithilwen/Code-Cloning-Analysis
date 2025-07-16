#include<atcoder/all>
using namespace atcoder;

#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int N, Q; scanf("%d%d", &N, &Q);
    fenwick_tree<LL> G(N);
    rep(i, N) { int a; scanf("%d", &a); G.add(i, a); }

    rep(q, Q) {
        int c; scanf("%d", &c);
        if (c == 0) {
            int p, x; scanf("%d%d", &p, &x);
            G.add(p, x);
        }
        if (c == 1) {
            int l, r; scanf("%d%d", &l, &r);
            printf("%lld\n", G.sum(l,r));
        }
    }

    return 0;
}