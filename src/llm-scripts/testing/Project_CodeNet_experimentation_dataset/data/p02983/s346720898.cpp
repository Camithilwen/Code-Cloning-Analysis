#include <bits/stdc++.h>
using namespace std;
#define BE(x) x.begin(), x.end()

int main() {
    long long l, r;
    cin >> l >> r;

    long long ans = 2019;
    int icnt = 0;
    for (long long i = l; i < r; i++) {
        int jcnt = 0;
        for (long long j = i+1; j <= r; j++) {
            ans = min(ans, i*j%2019);
            jcnt++;
            if (jcnt == 2020) break;
        }
        icnt++;
        if (icnt == 2020) break;
    }
    cout << ans << endl;
}