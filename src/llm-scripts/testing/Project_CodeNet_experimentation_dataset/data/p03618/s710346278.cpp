#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll R[400009];
    string s;
    cin >> s;
    ll n = s.size();
    map<char, int>mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
    }
    ll ans = n*(n-1)/2;
    for (auto& p : mp) {
        ll v = p.second;
        ans -= v*(v-1)/2;
    }
    cout << ans + 1 << endl;
}
