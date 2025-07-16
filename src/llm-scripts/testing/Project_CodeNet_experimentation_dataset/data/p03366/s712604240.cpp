#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    int N;
    ll S;
    cin >> N >> S;

    ll X[N], P[N];
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> P[i];
    }

    queue<ll> neg, pos;
    // Sより前、後にある座標をそれぞれ両端から入れていく
    for (int i = 0; i < N && X[i] < S; ++i) {
        neg.push(P[i]);
    }
    for (int i = N - 1; i >= 0 && X[i] > S; --i) {
        pos.push(P[i]);
    }

    vector<ll> route;
    // 最適解における探索順を後ろから

    int l = 0, r = N - 1;
    while (true) {
        // もう一方しか残っていない場合
        if (neg.empty()) {
            for (; l <= r; --r) {
                route.push_back(r);
            }
            break;
        }
        if (pos.empty()) {
            for (; l <= r; ++l) {
                route.push_back(l);
            }
            break;
        }

        // 末端の人口を比較、少ない方が選ばれる
        if (neg.front() >= pos.front()) {
            route.push_back(r);
            --r;
            neg.front() += pos.front();
            pos.pop();
        } else {
            route.push_back(l);
            ++l;
            pos.front() += neg.front();
            neg.pop();
        }
    }

    ll ans = 0, now = S;
    while (!route.empty()) {
        ll id = route.back();
        route.pop_back();
        ans += abs(X[id] - now);
        now = X[id];
    }

    cout << ans << endl;
    return 0;
}
