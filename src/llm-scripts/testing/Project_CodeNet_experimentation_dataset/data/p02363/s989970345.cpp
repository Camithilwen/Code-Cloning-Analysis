#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

using s64 = int64_t;

constexpr s64 INF = 1'010'000'000'000'000'000LL;

template<typename T, typename U>
bool chmin(T& xmin, const U& x)
{
    if(x < xmin) {
        xmin = x;
        return true;
    }
    else {
        return false;
    }
}

#define FOR(i, start, end) for(s64 i = (start); i < (end); ++i)
#define REP(i, n) FOR(i, 0, n)

s64 N;
s64 M;
vector<vector<s64>> G;

void print_g() {
    REP(i, N) {
        REP(j, N) {
            s64 c = G[i][j];
            if(c == INF)
                cout << "INF";
            else
                cout << c;
            cout << (j==N-1 ? '\n' : ' ');
        }
    }
}

void floyd() {
    REP(k, N) {
        REP(i, N) {
            if(G[i][k] == INF) continue;
            REP(j, N) {
                if(G[k][j] == INF) continue;
                chmin(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

void solve() {
    floyd();

    REP(i, N) {
        if(G[i][i] < 0) {
            cout << "NEGATIVE CYCLE\n";
            return;
        }
    }

    print_g();
}

int main() {
    cin >> N;
    G.assign(N, vector<s64>(N, INF));
    REP(i, N) { G[i][i] = 0; }

    cin >> M;
    REP(_, M) {
        s64 a, b, c; cin >> a >> b >> c;
        G[a][b] = c;
    }

    solve();

    return 0;
}