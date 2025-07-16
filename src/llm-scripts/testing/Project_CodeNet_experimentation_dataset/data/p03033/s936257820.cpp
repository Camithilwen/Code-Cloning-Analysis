#include <bits/stdc++.h>
using namespace std;

int main() {
    // 入力
    int N, Q;
    cin >> N >> Q;
    vector<int> S(N), T(N), X(N);
    for (int i = 0; i < N; i++) {
        cin >> S.at(i) >> T.at(i) >> X.at(i);
    }
    vector<int> D(Q);
    for (int i = 0; i < Q; i++) {
        cin >> D.at(i);
        D[i] = D[i];
    }

    // イベント
    vector<tuple<int, int, int>> event;
    for (int i = 0; i < N; i++) {
        event.push_back(make_tuple(S[i] - X[i], 1, X[i]));   // 通行止め開始イベント
        event.push_back(make_tuple(T[i] - X[i], -1, X[i]));  // 通行止め終了イベント
    }
    sort(event.begin(), event.end());  // 時系列順に並べる

    set<int> se;  // 現在出発した人が当たる可能性のある通行止めの情報を保存する set

    vector<int> ans(Q);
    int t = 0;
    int id = 0;
    for (int i = 0; i < Q; i++) {
        t = D[i];
        for (; id < (int)event.size() && get<0>(event[id]) <= t; id++) {
            if (get<1>(event[id]) == 1) {
                se.insert(get<2>(event[id]));
            } else {
                se.erase(get<2>(event[id]));
            }
        }
        if (se.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = *se.begin();
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
