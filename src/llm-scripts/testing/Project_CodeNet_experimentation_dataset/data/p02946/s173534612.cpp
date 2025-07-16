#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int k, n;
int main() {
    DAU
    cin >> k >> n;
    for (int i = n - k + 1; i < n + k; ++i)
        cout << i << ' ';
    PLEC
}
