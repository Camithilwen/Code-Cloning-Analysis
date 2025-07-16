#include <bits/stdc++.h>
using namespace std;

signed main() {
    int a[5], k;
    
    for ( int i = 0; i < 5; i++ ) {
        cin >> a[i];
    }
    cin >> k;
    sort(a, a + 5);
    
    cout << (a[4] - a[0] > k ? ":(\n" : "Yay!\n");
    return (0);
}