#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^18 -> 18回
// double pi = M_PI or acos(-1)
// printf("%.10f\n", ans);

const int MAX = 1000000001;

int main() {
    int n;
    cin >> n;
    map<ll, int> mp;
    string ans = "YES";
    rep(i, n) {
        ll tmp;
        cin >> tmp;
        if(mp.count(tmp) == 0) {
            mp[tmp] = 1;
        } else {
            ans = "NO";
        }
    }

    cout << ans << endl;

    return 0;
}
