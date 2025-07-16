#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 2e5 + 5;
int n;
int a[N];
int cnt[N];
int res;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i) {
        int Cnt = 0;
        for (int j = i + i; j <= n; j += i) {
            Cnt += cnt[j];
        }
        Cnt %= 2;
        if (a[i] != Cnt) {
            ++res;
            cnt[i] = 1;
        }
    }
    cout << res << endl;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i]) {
            cout << i << ' ';
        }
    }
    if (res)
        cout << endl;
    return 0;
}
