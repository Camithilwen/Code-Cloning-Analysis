
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    for (int i = 0; i < 2; ++i) {
        if (a > b) {
            ans += a;
            --a;
        } else {
            ans += b;
            --b;
        }
    }
    cout << ans << endl;

    return 0;
}

