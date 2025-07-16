#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;


    string s;

    while (n!=0) {
        n -= 1;

        ll k = n % 26;

        s += 'a' + k;
        

        n /= 26;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
}