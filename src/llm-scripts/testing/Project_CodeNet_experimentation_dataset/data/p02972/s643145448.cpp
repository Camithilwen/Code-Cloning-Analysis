#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int a[n+1];
    rep(i,n) cin >> a[i+1];
    int ans[n+1];
    rep(i,n) ans[i+1] = 0;
    //rep(i,n) cout << a[i] << endl;
    for(int i = n; i >= 1; --i) {
        //printf("OK\n");
        for(int j = i; j <= n; j += i) {
            ans[i] = (ans[i]+ans[j])%2;
        }
        ans[i] = (ans[i]+a[i])%2;
        //printf("OK2\n");
    }
    //rep(i,n) cout << ans[i+1] << endl;
    int cnt = 0;
    rep(i,n) {
        if(ans[i+1]) cnt++;
    }
    if (cnt) {
        cout << cnt << endl;
        rep(i,n) {
            if (ans[i+1]) {
                printf("%d\n", i+1);
            }
        }
    } else cout << 0 << endl;
    return 0;
}
