#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

class BIT {
    int n;
    vector<ll> node;

public:
    BIT(int N) : n(N), node(N + 1) {}
    void add(int i, ll x) {
        for (++i; i <= n; i += i & -i) { node[i] += x; }
    }
    ll sum(int i) {
        ll s = 0;
        for (; i > 0; i -= i & -i) { s += node[i]; }
        return s;
    }
};
class RSQ {
    int n;
    BIT a, b;

public:
    RSQ(int N) : n(N), a(N), b(N) {}
    void add(int l, int r, ll x) {
        int t = r - l;
        a.add(l, -l * x);
        a.add(r, r * x);
        b.add(l, x);
        b.add(r, -x);
    }
    ll sum(int i) { return a.sum(i) + i * b.sum(i); }
};

class Main {
    int N, K;
    vector<int> A;
    void input() {
        cin >> N >> K;
        A.resize(N);
        REP(i, N) { cin >> A[i]; }
    }
    void output() {
        REP(_, K) {
            vector<ll> imos(N + 2);
            REP(i, N) {
                imos[max(0, i - A[i]) + 1] += 1;
                imos[min(N, i + A[i] + 1) + 1] -= 1;
            }
            REP(i, N) {
                imos[i + 1] += imos[i];
                A[i] = imos[i + 1];
            }
            if (*min_element(A.begin(), A.end()) == N) break;
        }
        REP(i, N) { cout << A[i] << " "; }
        cout << endl;
    }

public:
    Main() {
        input();
        output();
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Main();

    return 0;
}
