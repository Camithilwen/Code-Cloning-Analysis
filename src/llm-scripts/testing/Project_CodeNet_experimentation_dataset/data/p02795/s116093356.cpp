#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long double ld;
typedef long long ll;
const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    int h, w, n; cin >> h >> w >> n;

    int ans = IINF;
    for(int i = 0; i <= h; i++){
        for(int j = 0; j <= w; j++){
            int sum = i * h + j * w - i * j;
            if(sum >= n) ans = min(ans, i + j);
        }
    }
    cout << ans << endl;

    return 0;
}
