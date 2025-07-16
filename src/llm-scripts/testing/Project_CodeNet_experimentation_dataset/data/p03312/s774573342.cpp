// ARC100
// D - Equal Cut

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 200000;
const ll INF = 1e18;

int N;
int A[MAX_N];
ll s[MAX_N + 1];

int search(int a, int b) {
    int l = a + 1, r = b - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (s[m] - s[a] <= s[b] - s[m]) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

ll solve() {
    s[0] = 0;
    for (int i = 1; i <= N; i++) {
        s[i] = s[i - 1] + A[i - 1];
    }

    ll ans = INF;
    for (int i = 1; i < N; i++) {
        int pq = search(0, i);
        int rs = search(i, N);
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ll pqrs[4] = {
                    s[pq + j] - s[0],
                    s[i] - s[pq + j],
                    s[rs + k] - s[i],
                    s[N] - s[rs + k],
                };
                sort(pqrs, pqrs + 4);
                ans = min(ans, pqrs[3] - pqrs[0]);
            }
        }
    }
    return ans;
}

int main() {
    cin >> N;
    A[0] = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
