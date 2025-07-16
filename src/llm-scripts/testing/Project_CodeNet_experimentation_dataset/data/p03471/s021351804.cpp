#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
signed main()
{
    int n;
    ll Y;
    cin >> n >> Y;

    for (int i = n; i >= 0; i--) {
        for (int j = 0; j <= n - i; j++) {
            int k = n - j - i;
            if (k < 0) {
                continue;
            }
            if (Y == 10000 * i + 5000 * j + 1000 * k) {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }

    put("-1 -1 -1");    

    return 0;
}