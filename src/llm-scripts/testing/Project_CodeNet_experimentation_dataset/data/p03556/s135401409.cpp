#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using ll = unsigned long long int;
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;

    do {
        double t = (int)sqrt(n);
        if (t * t == n) {
            cout << n << endl;
            return 0;
        }
    } while (n--);
}