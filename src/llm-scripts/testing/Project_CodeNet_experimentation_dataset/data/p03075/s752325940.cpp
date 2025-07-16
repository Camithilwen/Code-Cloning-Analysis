#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    int a, b, e, k;
    cin >> a;
    rep(i, 3) cin >> b;
    cin >> e >> k;
    if ((e - a) <= k) cout << "Yay!";
    else cout << ":(";
    cout << endl;
    return 0;
}