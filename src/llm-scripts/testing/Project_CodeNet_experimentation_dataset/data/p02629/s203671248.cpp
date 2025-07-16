#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

string alp = "zabcdefghijklmnopqrstuvwxy";

int main()
{
    
    ll n;
    cin >> n;
    string ans;
    while (n > 0) {
        int amari = n % 26;
        ans += alp[amari];
        if (n % 26 == 0) {
            n /= 26;
            n--;
        } else n /= 26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}