#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
    ll n; cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) perm[i] = i;

    double dist = 0;
    do {
        for (int i = 0; i < n - 1; ++i) {
            int xi = x[perm[i]];
            int nextxi = x[perm[i + 1]];
            int yi = y[perm[i]];
            int nextyi = y[perm[i + 1]];
            dist += sqrt(pow((nextxi - xi), 2) + pow((nextyi - yi), 2));
        }
    } while (next_permutation(perm.begin(), perm.end()));
    for (int i = 2; i <= n; ++i) {
        dist /= i;
    }
    cout << setprecision(20); 
    cout << dist << endl;
}