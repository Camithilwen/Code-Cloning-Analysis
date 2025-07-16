#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, l;
    cin >> n >> l;

    int ans = 0;
    if (l + n - 1 < 0) {
        for (int i = 0; i < n-1; i++) ans += l + i;
    } else if (l < 0) {
        for (int i = 0; i < n; i++) ans += l + i;
    } else {
        for (int i = 1; i < n; i++) ans += l + i;
    }

    cout << ans << endl;
    return 0;
}
