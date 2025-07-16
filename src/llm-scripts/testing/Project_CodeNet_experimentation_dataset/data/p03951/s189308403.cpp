#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    int N;
    string s, t;
    cin >> N >> s >> t;
    int cnt = 0;
    rep(i, N) {
        string left = s.substr(N - i - 1, i + 1);
        string right = t.substr(0, i + 1);
        if (right == left) cnt = i + 1;
    }
    cout << 2*N - cnt << endl;
    return 0;
}