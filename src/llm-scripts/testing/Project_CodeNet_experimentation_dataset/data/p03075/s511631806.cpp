#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    int a, b, c, d, e, k;
    cin >> a >> b >> c >> d >> e >> k;
    if (e - a <= k) {
        cout << "Yay!" << endl;
    } else {
        cout << ":(" << endl;
    }
    return 0;
}