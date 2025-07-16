#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

    int X, Y;
    cin >> X >> Y;
    int ans = 0;
    switch(X) {
        case 1:
            ans += 300000;
            break;
        case 2:
            ans += 200000;
            break;
        case 3:
            ans += 100000;
            break;
    }
    switch(Y) {
        case 1:
            ans += 300000;
            break;
        case 2:
            ans += 200000;
            break;
        case 3:
            ans += 100000;
            break;
    }

    if (X == 1 && Y == 1) ans += 400000;
    cout << ans << endl;
    
    return 0;
}