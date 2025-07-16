#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N, L;
    cin >> N >> L;

    int orderL = L;
    int orderR = L + N - 1;
    int eat;

    if(0 < orderL) {
        eat = orderL;
    } else if(orderR < 0) {
        eat = orderR;
    } else {
        eat = 0;
    }

    int ans = (orderL + orderR) * (orderR - orderL + 1) / 2 - eat;

    cout << ans << endl;

    return 0;
}
