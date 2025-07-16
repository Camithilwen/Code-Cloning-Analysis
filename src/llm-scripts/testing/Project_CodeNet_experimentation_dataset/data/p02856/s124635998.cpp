/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.18 17:43:20
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    int m;cin >> m;
    ll total = 0;
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ll d,c;cin >> d >> c;
        ans += c;
        total += (d * c - 1) % 9 + 1;
        ans += (d * c - 1) / 9;
    }
    ans += (total - 1) / 9;
    cout << ans - 1 << endl;
    return 0;
}