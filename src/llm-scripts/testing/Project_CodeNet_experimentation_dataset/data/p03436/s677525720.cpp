/**
*    created: 25.07.2020 06:24:27
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx2[8]={0, 1, 0, -1, 1, 1,-1, -1};
const int dy2[8]={1, 0,-1, 0, 1, -1, 1, -1};
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

void gridbfs(int i,int j,vector<string> s,vector<vector<int>> &dis) {
    int h = s.size(), w = s[0].size();
    queue<vector<int>> q; q.push({i,j});
    dis[i][j] = 0;
    while (!q.empty()) {
        auto v = q.front(); q.pop();
        if (v[0] > 0 && s[v[0] - 1][v[1]] == '.' && dis[v[0] - 1][v[1]] == -1) {
           dis[v[0] - 1][v[1]] = dis[v[0]][v[1]] + 1;
           q.push({v[0] - 1, v[1]});
        }
        if (v[1] > 0 && s[v[0]][v[1] - 1] == '.' && dis[v[0]][v[1] - 1] == -1) {
           dis[v[0]][v[1] - 1] = dis[v[0]][v[1]] + 1;
           q.push({v[0], v[1] - 1});
        }
        if (v[0] < h - 1 && s[v[0] + 1][v[1]] == '.' && dis[v[0] + 1][v[1]] == -1) {
            dis[v[0] + 1][v[1]] = dis[v[0]][v[1]] + 1;
            q.push({v[0] + 1, v[1]});
        }
        if (v[1] < w - 1 && s[v[0]][v[1] + 1] == '.' && dis[v[0]][v[1] + 1] == -1) {
            dis[v[0]][v[1] + 1] = dis[v[0]][v[1]] + 1;
            q.push({v[0], v[1] + 1});
        }
    }
    return;
}

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int h, w; cin >> h >> w;
    vector<string> v(h);
    int bcnt = 0;
    rep(i,h) cin >> v[i];
    rep(i,h) rep(j,w) if (v[i][j] == '#') bcnt++;
    vector<vector<int>> dis(h,vector<int>(w,-1));
    gridbfs(0,0,v,dis);
    if (dis[h-1][w-1] == -1) cout << -1 << endl;
    else cout << h * w - bcnt - dis[h-1][w-1] - 1 << endl;
    return 0;
}