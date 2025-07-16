#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define inf LLONG_MAX
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
const string MINUSINF = "-";

void chmax(string &a, string b) {
    if (a == MINUSINF) a = b;
    else if (a.size() < b.size()) a = b;
    else if (a.size() == b.size()) {
        if (a < b) a = b;
    }
}

ll match[10] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
string dp[11000];



int main()
{
    ll N, M; cin >> N >> M;
    vll A(M);
    rep(i, M) cin >>  A[i];

    rep(i, 11000) dp[i] = MINUSINF;

    dp[0] = "";
    for (int i = 0; i <= N; i++) {
        if (dp[i] == MINUSINF) continue;
        for (auto a : A) chmax(dp[i + match[a - 1]], dp[i] + (char)('0' + a));
    }
    cout << dp[N] << endl;
    return 0;
}