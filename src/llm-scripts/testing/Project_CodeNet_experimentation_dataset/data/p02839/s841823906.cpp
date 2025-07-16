#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

llong h, w;
llong a[100][100];
llong b[100][100];
llong v[100][100];
llong u[100][100];
bool dp[100][100][26000];
llong offset = 13000;

int main() {
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            v[i][j] = a[i][j] - b[i][j];
            u[i][j] = b[i][j] - a[i][j];
        }
    }

    dp[0][0][offset] = true;
    dp[0][1][offset] = true;
    dp[1][0][offset] = true;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            for (int k = 0; k < 26000; k++) {
                if (dp[i - 1][j][k] == true) {
                    dp[i][j][k + v[i][j]] = true;
                    dp[i][j][k + u[i][j]] = true;
                }
                if (dp[i][j - 1][k] == true) {
                    dp[i][j][k + v[i][j]] = true;
                    dp[i][j][k + u[i][j]] = true;
                }
            }
        }
    }

    llong ans = 1ll << 60ll;
    for (int k = 0; k < 26000; k++) {
        if (dp[h][w][k] == true) {
            ans = min(ans, llabs(k - offset));
        }
    }

    cout << ans << endl;

    return 0;
}
