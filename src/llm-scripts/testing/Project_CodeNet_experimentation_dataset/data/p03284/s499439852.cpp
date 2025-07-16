#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,i; cin >> n >> i;
    int ans = 1;
    if(n%i == 0) ans = 0;
    cout << ans << endl;
}