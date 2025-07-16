#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
int N, K;


void input() {
    cin >> N >> K;
}


int main() {
    input();
    int ans = 1;
    rep(i, N) {
        if (ans < K) ans *= 2;
        else ans += K;
    }
    cout << ans << endl;
}
