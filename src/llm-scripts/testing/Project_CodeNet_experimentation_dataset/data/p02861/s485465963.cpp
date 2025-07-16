#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MN = 1e5 + 5;
int x[8], y[8];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
    vector<int> v(N);
    iota(all(v), 0);
    do {
        double cur = 0;
        for (int i = 1; i < N; i++) {
            int dx = x[v[i]]-x[v[i-1]], dy = y[v[i]]-y[v[i-1]];
            cur += sqrt(dx*dx+dy*dy);
        }
        sum += cur;
        cnt++;
    } while (next_permutation(all(v)));
    cout << fixed << setprecision(7) << sum / cnt << '\n';
    return 0;
}