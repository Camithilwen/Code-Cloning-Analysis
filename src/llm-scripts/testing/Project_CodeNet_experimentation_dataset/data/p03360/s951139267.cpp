#include <bits/stdc++.h>
using namespace std;  

int main() {
    int a, b, c, k, tem, ans;
    
    cin >> a >> b >> c >> k;
    ans = a + b + c - max({a, b, c});
    
    tem = max({a, b, c});
    for ( int i = 0; i < k; i++ ) {
        tem *= 2;
    }
    cout << ans + tem << endl;
    
    return (0);
}