#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 4e18;

struct STNode {
    typedef STNode* NP;
    NP l, r;
    int sz;
    ll mi;
    STNode(int _sz) : sz(_sz) {
        mi = INF;
        if (sz == 1) return;
        l = new STNode(sz/2);
        r = new STNode(sz-sz/2);
    }
    void set(int k, ll x) {
        if (sz == 1) {
            mi = min(mi, x);
            return;
        }
        if (k < sz/2) {
            l->set(k, x);
        } else {
            r->set(k-sz/2, x);
        }
        mi = min(l->mi, r->mi);
    }
    ll get(int a, int b) {
        if (b <= 0 || sz <= a) return INF;
        if (a <= 0 && sz <= b) return mi;
        return min(l->get(a, b), r->get(a-sz/2, b-sz/2));
    }
};

const int MN = 222222;
int n, q, a, b;
int x[MN];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> q >> a >> b;
    x[0] = a;
    for (int i = 1; i <= q; i++) {
        cin >> x[i];
    }
    
    STNode* tr = new STNode(n+1);
    STNode* tr1 = new STNode(n+1);
    STNode* tr2 = new STNode(n+1);
    tr->set(b, 0);
    tr1->set(b, -b);
    tr2->set(b, b);
    
    ll sm = 0;
    for (int i = 0; i < q; i++) {
        ll c = min(tr1->get(1, x[i+1]+1) + sm + x[i+1], tr2->get(x[i+1]+1, n+1) + sm - x[i+1]);
        sm += abs(x[i+1] - x[i]);
        tr->set(x[i], c - sm);
        tr1->set(x[i], c - x[i] - sm);
        tr2->set(x[i], c + x[i] - sm);
    }
    cerr << tr->get(x[0], x[0]+1) + sm << endl;
    cout << tr->get(1, n+1) + sm << endl;
    return 0;
}