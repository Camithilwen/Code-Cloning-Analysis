// @author PraveenKumarRana

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define int long long int
#define vi vector<int>
#define pi pair<int, int>
#define IOS std::ios_base::sync_with_stdio(false);
#define all(x) x.begin(), x.end()
#define f(i, a, n) for (int i = a; i < n; i++)
#define fr(i, n, a) for (int i = n - 1; i >= a; --i)

const int mod = 1e9 + 7;
const int inf = 1e16 + 7;

void SOLVE() {
    // Write your code here ?
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    f(i, 0, k) {
        int x;
        cin >> x;
        mp[x] = 1;
    }

    while (true) {
        bool ok = true;
        int N = n;
        while (N > 9) {
            if (!mp[N % 10]) {
                N /= 10;
            } else {
                ok = false;
                break;
            }
        }

        if (N > 0 && !mp[N]) {
            N /= 10;
        } else {
            ok = false;
        }

        if (!ok) {
            N = n + 1;
            n++;
        } else {
            break;
        }
    }

    cout << n << endl;
}

int32_t main() {
    IOS;
    SOLVE();
    return 0;
}
