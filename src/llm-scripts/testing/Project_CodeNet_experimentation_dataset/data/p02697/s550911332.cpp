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
    int N, M;
    cin >> N >> M;

    vector<bool> used(N);
    vector<pair<int, int>> arenas;

    for (int i = 0; i < M; i++) {
        int left = i + 1;
        int right = N - i;
        if (N % 2 == 0 && left * 2 * 2 > N) {
            left++;
        }
        arenas.push_back(make_pair(left, right));
    }

    for (int i = 0; i < M; i++) {
        int left = arenas[i].first;
        int right = arenas[i].second;
        printf("%d %d\n", left, right);
    }

    return 0;
}
