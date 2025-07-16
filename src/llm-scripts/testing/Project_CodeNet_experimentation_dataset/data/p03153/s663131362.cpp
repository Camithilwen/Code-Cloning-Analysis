#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
typedef pair<int, int> ii;
typedef pair<long long, int> li;
typedef pair<long long, pair<int, int> > lii;

const int N = 2e5 + 5;
const long long inf = 1e18 + 123;
int n, a[N], d;
long long ans;
vector<ii> vec;
vector<lii> edge;

struct Bit1 {
    vector<li> node;
    Bit1 (int sz = 0) {
        node.assign(sz + 5, li(inf, 0) );
    }
    void update (int pos, li val) {
        for (; pos < (int)node.size(); pos += pos & -pos) node[pos] = min(node[pos], val);
    }
    li get (int pos) {
        li ret = li(inf, 0);
        for (; pos > 0; pos -= pos & -pos) ret = min(ret, node[pos]);
        return ret;
    }
};

struct Bit2 {
    vector<li> node;
    Bit2 (int sz = 0) {
        node.assign(sz + 5, li(inf, 0) );
    }
    void update (int pos, li val) {
        pos = (int)node.size() - pos;
        for (; pos < (int)node.size(); pos += pos & -pos) node[pos] = min(node[pos], val);
    }
    li get (int pos) {
        pos = (int)node.size() - pos;
        li ret = li(inf, 0);
        for (; pos > 0; pos -= pos & -pos) ret = min(ret, node[pos]);
        return ret;
    }
};

struct Dsu {
    vector<int> pSet, szSet;
    Dsu (int _n = 0) {
        pSet.assign(_n + 5, 0); for (int i = 0; i < (int)pSet.size(); ++i) pSet[i] = i;
        szSet.assign(_n + 5, 1);
    }
    int findSet (int i) { return i == pSet[i] ? i : pSet[i] = findSet(pSet[i]); }
    bool unionSet (int i, int j) {
        i = findSet(i);
        j = findSet(j);
        if (i == j) return false;
        if (szSet[i] > szSet[j]) swap(i, j);
        szSet[j] += szSet[i];
        pSet[i] = j;
        return true;
    }
};

long long cost (int i, int j) { return 1LL * abs(i - j) * d + a[i] + a[j]; }

int main () {
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        vec.pb(ii(a[i], i) );
    }
    sort(vec.begin(), vec.end() );

    Bit1 bit1(n);
    Bit2 bit2(n);

    for (auto _ : vec) {
        int i = _.se;
        li tmp1 = bit1.get(i), tmp2 = bit2.get(i);
        if (tmp1.se) edge.pb(lii(cost(tmp1.se, i), ii(tmp1.se, i) ) );
        if (tmp2.se) edge.pb(lii(cost(tmp2.se, i), ii(tmp2.se, i) ) );
        bit1.update(i, li(a[i] - 1LL * i * d, i) );
        bit2.update(i, li(a[i] + 1LL * i * d, i) );
    }
    sort(edge.begin(), edge.end() );

    Dsu dsu(n);

    for (auto _ : edge) {
        if (dsu.unionSet(_.se.fi, _.se.se) ) ans += _.fi;
    }

    cout << ans;

    return 0;
}
