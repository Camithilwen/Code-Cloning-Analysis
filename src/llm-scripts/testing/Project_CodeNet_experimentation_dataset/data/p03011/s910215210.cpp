#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int p, q, r;
    cin >> p >> q >> r;

    int ans = min(p+q, min(q+r, r+p));
    cout << ans << endl;
    return 0;
}
