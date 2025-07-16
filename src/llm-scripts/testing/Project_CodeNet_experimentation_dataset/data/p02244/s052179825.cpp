#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 8;

string S[MAX];
ll x[8] = {1, 1, 1, 0, -1, -1, -1, 0};
ll y[8] = {1, 0, -1, -1, -1, 0, 1, 1};

bool dfs() {
    vector<vector<bool>> U(MAX, vector<bool>(MAX, true));
    ll cnt = 0;
    REP(h, MAX) {
        REP(w, MAX) {
            if (S[h][w] == '.')
                continue;
            cnt++;
            REP(i, 8) {
                ll mul = 0;
                while (true) {
                    ll nx = x[i] * mul + h, ny = y[i] * mul + w;
                    if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX)
                        break;
                    U[nx][ny] = false;
                    mul++;
                }
            }
        }
    }

    if (cnt == 8) {
        REP(h, MAX) {
            cout << S[h] << endl;
        }
        return true;
    }

    REP(h, MAX) {
        REP(w, MAX) {
            if (!U[h][w])
                continue;
            S[h][w] = 'Q';
            if (dfs())
                return true;
            S[h][w] = '.';
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i, MAX) {
        string s = "";
        REP(j, MAX) {
            s.push_back('.');
        }
        S[i] = s;
    }
    ll N;
    cin >> N;
    REP(i, N) {
        pll p;
        cin >> p.first >> p.second;
        S[p.first][p.second] = 'Q';
    }

    dfs();

    return 0;
}
