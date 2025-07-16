#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    ll x, y;
    cin >> x >> y;
    if(x == y)cout << 0 << endl;
    else if(x == -y)cout << 1 << endl;
    else if(abs(x) < abs(y)){
        ll ans = abs(y) - abs(x);
        if(x < 0 && y < 0)ans += 2;
        else if(x < 0 || y < 0)ans++;
        cout << ans << endl;
    }else{
        ll ans = abs(x) - abs(y);
        if(x > 0 && y > 0)ans += 2;
        else if(x > 0 || y > 0)ans++;
        cout << ans << endl;
    }
    
}