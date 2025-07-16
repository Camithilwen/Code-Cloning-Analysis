#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int h, w, n;
    cin >> h >> w >> n;

    int div = n / max(h, w);
    int rem = n % max(h, w);

    if (rem) cout << div + 1 << '\n';
    else cout << div << '\n';
    return 0;
}