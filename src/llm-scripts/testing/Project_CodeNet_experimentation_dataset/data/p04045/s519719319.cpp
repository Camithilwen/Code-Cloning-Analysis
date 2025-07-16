#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> v(10, true);
    rep(i, k) {
        int a;
        cin >> a;
        v[a] = false;
    }
    while(1) {
        int ans = n;
        while(ans > 0) {
            if (!v[ans % 10]) {
                break;
            }
            ans /= 10;
        }
        if (ans == 0) break;
        n++;
    }
    cout << n << "\n";
}