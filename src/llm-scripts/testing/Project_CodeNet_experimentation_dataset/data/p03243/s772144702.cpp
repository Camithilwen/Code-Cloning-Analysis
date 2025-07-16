#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N; cin >> N;
    int x, ans;
    for (int i = 9; i >= 1; i--) {
        x = i * 111;
        if (N <= x) ans = x;
    }
    cout << ans << endl;
    return 0;
}