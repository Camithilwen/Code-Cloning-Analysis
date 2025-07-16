#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> primes;
    rep2(i, 2, 55555) {
        bool flag = true;
        rep(j, primes.size()) {
            if (i%primes[j] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) primes.push_back(i);
    }
    vector<int> ans;
    rep(i, primes.size()) {
        if (primes[i]%5 == 1) ans.push_back(primes[i]);
    }
    rep(i, N) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}
