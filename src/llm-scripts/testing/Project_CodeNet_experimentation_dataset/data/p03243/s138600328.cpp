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

int n;
int main() {
    cin >> n;
    for (int i = 1; i < 10; ++i) {
        if (i * 111 >= n) {
            cout << i * 111 << endl;
            exit(0);
        }
    }
    return 0;
}
