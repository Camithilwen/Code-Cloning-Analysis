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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int K, T;
    cin >> K >> T;
    vector<int> a(T);
    priority_queue<P> pq;
    REP(i, T) {
        cin >> a[i];
        pq.emplace(a[i], i);
    }
    while (pq.size() >= 2) {
        int b, c, i, j;
        tie(b, i) = pq.top();
        pq.pop();
        tie(c, j) = pq.top();
        pq.pop();
        if (b > 1) {
            pq.emplace(b - 1, i);
        }
        if (c > 1) {
            pq.emplace(c - 1, j);
        }
    }
    cout << pq.top().first - 1 << endl;

    return 0;
}
