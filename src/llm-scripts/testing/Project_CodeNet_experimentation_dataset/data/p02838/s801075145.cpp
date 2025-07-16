#include <bits/stdc++.h>
//#include "atcoder/all"
typedef long long int ll;
using namespace std;
// using namespace atcoder;
#define MAXN 300001
#define mod 1000000007
ll a[MAXN];
int main() {
    int n;
    cin >> n;
    ll co[60];
    for (int i = 0; i < 60; i++) co[i] = 0;
    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        int count = 0;
        while (a) {
            co[count]+= a % 2;
            a /= 2;
            count++;
        }
    }
    ll ret = 0;
    int now = 1;
    for (int i = 0; i < 60; i++) {
        ret = (ret + (now * co[i] % mod)  * (n - co[i])) % mod;
        now = now * 2 % mod;
    }
    cout << ret << endl;
    return 0;
}