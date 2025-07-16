#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n;
    int mul[1001];
    int kmax = 0;
    cin >> n;
    for (int i =0; i <= n; ++i)
        mul[i] = 0;
    for (int i = 2; i <= n; ++i) {
        int j = i;
        int k = 2;
        while(j > 1) {
            if (j % k == 0) {
                j /= k;
                ++mul[k];
            }
            else
                ++k;
        }
        if (k > kmax)
            kmax =k;
    }
    long long ans = 1;
    for (int i = 2; i <=kmax; ++i)
        (ans *= mul[i]+1) %= mod;
    cout << ans;

}

int main() {

    solve();
    return 0;
}
