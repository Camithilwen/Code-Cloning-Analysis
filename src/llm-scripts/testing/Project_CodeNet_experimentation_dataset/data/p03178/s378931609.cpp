#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define _ std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int mod = 1e9+7;
const int LOG = 17;
const int N = 5e5+123;
const ll INF = (ll)1e18 + 7;

int dp[10010][110];

int main()
{
    string s;
    cin >> s;
    int d;
    cin >> d;
    dp[0][0] = 1;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k <= 9; k++) {
                dp[i + 1][(j + k) % d] += dp[i][j];
                dp[i + 1][(j + k) % d] %= mod;
            }
        }
    }
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s[i] - '0'; j++) {
            ans += dp[(int)s.size() - i - 1][(d - (sum + j) % d) % d];
            ans %= mod;
        }
        sum += s[i] - '0';
    }
    if (sum % d == 0) {
        ans++;
    }
    ans += mod - 1;
    ans %= mod;
    cout << ans;
    return 0;
}
