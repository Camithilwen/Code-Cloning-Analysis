#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
using namespace std;

void erase1(multiset<int> &s, int x) {
    auto it = s.find(x);
    if (it != s.end()) s.erase(it);
}

const int INF = 1<<30;

vector<int> solve(int H, int W, const int *L, const int *R) {
    map<int, int> m;
    multiset<int> distances;
    vector<int> ans(H);
    for (int i = 0; i < W; i++) {
        m[i] = 0;
        distances.insert(0);
    }
    for (int h = 0; h < H; h++) {
        int l = L[h], r = R[h];
        auto it = m.lower_bound(l);
        int d = INF;
        while (it != m.end() && it->first <= r) {
            d = min(d, it->second + r + 1 - it->first);
            erase1(distances, it->second);
            it = m.erase(it);
        }
        if (d < INF && r < W - 1) {
            if (it == m.end() || it->first > r + 1) {
                m[r+1] = d;
                distances.insert(d);
            } else if (d < it->second) {
                erase1(distances, it->second);
                distances.insert(d);
                m[r+1] = d;
            }
        }
        ans[h] = distances.empty() ? -1 : *distances.begin() + h + 1;
    }
    return ans;
}

vector<int> check(int H, int W, const int *L, const int *R) {
    int dp[H+1][W];
    fill(dp[0], dp[0]+W, 0);
    for (int i = 1; i <= H; i++) {
        dp[i][0] = L[i-1] == 0 ? INF : dp[i-1][0];
        for (int j = 1; j < W; j++) {
            if (j < L[i-1]) dp[i][j] = min(dp[i-1][j], dp[i][j-1] + 1);
            else if (j <= R[i-1]) dp[i][j] = dp[i][j-1] + 1;
            else dp[i][j] = min(dp[i-1][j], dp[i][j-1] + 1);
        }
    }

    vector<int> ans(H);
    for (int h = 0; h < H; h++) {
        ans[h] = h + 1 + *min_element(dp[h+1], dp[h+1] + W);
        if (ans[h] >= INF) ans[h] = -1;
    }
    return ans;
}


int main() {
    int H, W; scanf("%d %d", &H, &W);
    int L[H], R[H];
    for (int i = 0; i < H; i++) {
        scanf(" %d %d ", &L[i], &R[i]);
        L[i]--; R[i]--;
    }
    vector<int> ans = solve(H, W, L, R);
    for (int x : ans) printf("%d\n", x);

    // vector<int> expect = check(H, W, L, R);
    // for (int x : expect) cerr << x << endl;
    // for (int i = 0; i < H; i++) assert(ans[i] == expect[i]);
}
