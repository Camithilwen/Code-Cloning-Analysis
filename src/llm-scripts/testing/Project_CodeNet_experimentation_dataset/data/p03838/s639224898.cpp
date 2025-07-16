#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;

int main() {

    ll x,y;
    cin >> x >> y;
    ll ans;
    if (x * y > 0) {
        if (y >= x) ans = y - x;
        else ans = x - y + 2;
    } else if (x * y < 0) {
        ans = abs(abs(x)-abs(y)) + 1;
    } else {
        if (y > x) ans = y - x;
        else ans = x - y + 1;
        
    }
    cout << ans << endl;
    return 0;
}
