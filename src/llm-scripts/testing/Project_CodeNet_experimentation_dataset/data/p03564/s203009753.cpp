#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, r = 1;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        r += min(r, k);
    cout << r;
}