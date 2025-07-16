#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

bool check(int N, int M, vector<vector<int>> a, int x) {
    vector<deque<int>> list(M);
    vector<bool> playable(M, true);
    vector<deque<int>> A(N);
    rep(i,N) rep(j,M) A[i].push_back(a[i][j]);
    rep(i,N) {
        int k = A[i].front(); A[i].pop_front();
        list[k].push_back(i);
    }
    while (true) {
        int flag = -1;
        int max_count = x;
        rep(i,M) {
            if (list[i].size() > max_count) {
                flag = i;
                max_count = list[i].size();
            }
        }
        if (flag < 0) {
            return true;
        }
        playable[flag] = false;

        while (!list[flag].empty()) {
            int i = list[flag].front(); list[flag].pop_front();
            while (true) {
                if (A[i].empty()) return false;
                int k = A[i].front(); A[i].pop_front();
                if (playable[k]) {
                    list[k].push_back(i);
                    break;
                }
            }
        }
    }
}

int main() {

    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    rep(i,N) rep(j,M) {
        cin >> A[i][j];
        A[i][j]--;
    }

    for (int i = 1; i <= N; i++) {
        if (check(N, M, A, i)) {
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}