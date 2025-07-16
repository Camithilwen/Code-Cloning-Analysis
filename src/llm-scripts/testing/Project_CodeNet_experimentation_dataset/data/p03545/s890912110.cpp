#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;

int calc(vector<int> N, int i, int j, int k) {
    return N.at(0) + pow(-1, i) * N.at(1) + pow(-1, j) * N.at(2)+pow(-1, k) * N.at(3);
}

void prt(vector<int> N, vector<int> P) {
    cout << N.at(0);
    rep(i, 3) {
        if (P.at(i) % 2 == 0) cout << "+"; else cout << "-";
        cout << N.at(i + 1);
    }
    cout << "=7" << endl;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    vector<int> N(4);
    rep(i, 4) N.at(i) = S.at(i) - 48;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k =0; k < 2; k++) {
                vector<int> parity = {i, j, k};
                if (calc(N, i, j, k) == 7) {
                    prt(N, parity);
                    return 0;
                }
            }
        }
    }
    return 0;
}
