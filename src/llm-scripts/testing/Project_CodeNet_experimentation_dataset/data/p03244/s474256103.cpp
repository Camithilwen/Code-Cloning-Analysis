#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define nl '\n'
#define INF 1e9 + 5
#define f(i, n) for (int i = 0; i < n; ++i)

using namespace std;
pair<int, int> get(vector<int>& a, bool even, int skip) {
    int n = a.size();
    unordered_map<int, int> book;
    pair<int, int> res = {0, 0};
    if (even) {
        for (int i = 0; i < n; ++i) {
            if (i & 1 || a[i] == skip) continue;
            if (book.count(a[i]))
                book[a[i]]++;
            else
                book[a[i]] = 1;
            if (res.second < book[a[i]]) {
                res.first = a[i];
                res.second = book[a[i]];
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (!(i & 1) || a[i] == skip) continue;
            if (book.count(a[i]))
                book[a[i]]++;
            else
                book[a[i]] = 1;
            if (res.second < book[a[i]]) {
                res.first = a[i];
                res.second = book[a[i]];
            }
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    int m = n / 2;
    pair<int, int> one = get(a, true, INF);
    pair<int, int> two = get(a, false, one.first);
    pair<int, int> three = get(a, false, INF);
    pair<int, int> four = get(a, true, one.first);
    int ans = min({(m - one.second) + (m - two.second),
                   (m - three.second) + (m - four.second)});
    cout << ans << nl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}