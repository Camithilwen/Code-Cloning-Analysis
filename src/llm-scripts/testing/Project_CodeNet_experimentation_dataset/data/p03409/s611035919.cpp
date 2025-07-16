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

int main(void) {
    int N;
    cin >> N;

    vector<pair<int, int>> reds(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        reds[i] = {a, b};
    }
    // descending order by y
    sort(reds.begin(), reds.end(), [](const pair<int, int> a, const pair<int, int> b) {
            return a.second > b.second;
                    });

    vector<pair<int, int>> blues(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        blues[i] = {a, b};
    }
    sort(blues.begin(), blues.end());

    int cnt = 0;
    vector<bool> used_red(N, false);

    for (int bi = 0; bi < N; bi++) {
        for (int ri = 0; ri < N; ri++) {
            if (used_red[ri]) {
                continue;
            }
            auto blue = blues[bi];
            auto red = reds[ri];
            if (red.first < blue.first && red.second < blue.second) {
                cnt++;
                used_red[ri] = true;
                break;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
