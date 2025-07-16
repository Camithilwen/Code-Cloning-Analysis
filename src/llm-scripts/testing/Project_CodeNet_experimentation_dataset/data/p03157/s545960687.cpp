#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<tuple>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = (1LL << 62);
ll n,k, m, t; string s;
const ld PI = acos(-1);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}bool visit[410][410],b[410][410]; vector<vector<char>> c;
ll cc[2],ans = 0;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
void dfs(int x,int y) {
    cc[b[y][x]]++;
    rep(i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
        if (visit[ny][nx] || b[ny][nx] == b[y][x])continue;
        visit[ny][nx] = 1;
        dfs(nx, ny);
    }
}
int main() {
    cin >> n >> m; vector<vector<char>> c(n, vector<char>(m));
    Fill(visit, 0);
    rep(i, n) {
        rep(j, m) {
            cin >> c[i][j];
            b[i][j] = (c[i][j] == '#');
        }
    }
    rep(i, n) {
        rep(j, m) {
            if (visit[i][j]) continue;
            visit[i][j] = 1;
            cc[0] = 0; cc[1] = 0;
            dfs(j, i);
            ans += cc[0] * cc[1];
        }
    }cout << ans << endl;
}