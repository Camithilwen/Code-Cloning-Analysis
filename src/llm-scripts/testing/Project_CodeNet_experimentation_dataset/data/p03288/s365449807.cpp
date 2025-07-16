#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    string ans;
    if(n < 1200) ans = "ABC";
    else if(n < 2800) ans = "ARC";
    else ans = "AGC";
    cout << ans << endl; 
}