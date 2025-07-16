#include<bits/stdc++.h>
using namespace std;

int main () {
    int x, ans = 0;
    cin >> x;

    ans += x/500*1000;
    x -= x/500*500;
    ans += x/5*5;
    cout << ans << endl;
}