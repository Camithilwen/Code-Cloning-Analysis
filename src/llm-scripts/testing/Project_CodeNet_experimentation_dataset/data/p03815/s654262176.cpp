#include <bits/stdc++.h>
using namespace std;

int main(){
    long x, ans = 0;
    cin >> x;
    ans += 2 * (x / 11);
    x %= 11;
    if(x > 0) ans++;
    if(x > 6) ans++;
    cout << ans << endl;
    return 0;
}