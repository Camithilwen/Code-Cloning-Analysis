#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

vector<int> problems;
vector<int> bonus;

int solve(const int bits, const int D, const ll G) {
    ll score = 0;
    int ans = 0;
    priority_queue<int> que;
    for (int i = 0; i < D; i++) {
        if (bits & (1 << i)) {
            score += (i + 1) * 100 * problems[i];
            score += bonus[i];
            ans += problems[i];
        } else {
            for (int j = 0; j < max(0, problems[i] - 1); j++) {
                que.push((i + 1) * 100);
            }
        }
    }

    while (!que.empty() && score < G) {
        auto v = que.top();
        que.pop();
        score += v;
        ans++;
    }

    if (score < G) {
        return -1;
    } else {
        return ans;
    }
}

int main(void) {
    int D;
    ll G;
    cin >> D >> G;

    problems.resize(D);
    bonus.resize(D);
    for (int i = 0; i < D; i++) {
        cin >> problems[i] >> bonus[i];
    }

    int ans = INT_MAX / 2;

    for (int bits = 0; bits < (1 << D); bits++) {
        int cand = solve(bits, D, G);
        if (cand >= 0) {
            // printf("bits: %x, required: %d\n", bits, cand);
            chmin(ans, cand);
        }
    }

    cout << ans << endl;

    return 0;
}
