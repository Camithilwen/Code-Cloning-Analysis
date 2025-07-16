#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

const int N = 1e5 + 7;
const int L = 17;

int go[N][L];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    int l;
    cin >> l;
    vector <int> who(n);
    int ptr = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        while (ptr > i && x[ptr] - x[i] > l) ptr--;
        who[i] = ptr;
    }
    for (int i = n - 1; i >= 0; i--) {
        go[i][0] = who[i];
        for (int j = 1; j < L; j++) {
            go[i][j] = go[go[i][j - 1]][j - 1];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a > b) swap(a, b);
        int pos = a;
        int res = 0;
        for (int i = L - 1; i >= 0; i--) {
            if (go[pos][i] < b) {
                pos = go[pos][i];
                res += (1 << i);
            }
        }
        cout << res + 1 << '\n';
    }
    return 0;
} 