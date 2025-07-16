#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

// Sum of digits in base 10 is a multiple of D
ll generate(ll depth, ll sum, bool tight, ll D, const string& digits, vector<vector<vector<ll>>>& memo) {
    if (depth == digits.size()) {
        return sum % D == 0;
    }
    if (memo[depth][sum][tight] != -1) {
        return memo[depth][sum][tight];
    }
    ll limSup = tight ? (digits[depth] - '0') : 9;
    ll ans = 0;
    for (ll d = 0; d <= limSup; d++) {
        bool newTight = tight && d == limSup;
        ans = (ans + generate(depth + 1, (sum + d) % D, newTight, D, digits, memo)) % MOD;
    }
    return memo[depth][sum][tight] = ans;
}

int main() {
    string s;
    cin >> s;
    ll D;
    cin >> D;
    ll n = s.size();
    vector<vector<vector<ll>>> memo(n, vector<vector<ll>>(D, vector<ll>(2, -1)));
    ll ans = generate(0, 0, true, D, s, memo);
    cout << (ans - 1 + MOD) % MOD << "\n"; // don't count 0
}