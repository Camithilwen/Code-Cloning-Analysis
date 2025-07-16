#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string s[410];
bool seen[410][410];
int h, w;
ll cnt_w, cnt_b;

void bfs(int sx, int sy){
    queue<pair<int,int>> que;
    que.push({sx,sy});
    while(!que.empty()){
        pair<int,int> p = que.front();
        que.pop();
        int x = p.first;
        int y = p.second;

        if (s[y][x] == '#') cnt_b++;
        else if (s[y][x] == '.') cnt_w++;
        rep(i, 4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || w <= nx || ny < 0 || h <= ny) continue;
            else if (seen[ny][nx]) continue;
            else if (s[ny][nx] != s[y][x]) {
                seen[ny][nx] = true;
                que.push({nx,ny});
            }
        }
    }
}

int main(){
    cin >> h >> w;
    rep(i, h) cin >> s[i];
    ll ans = 0;

    rep(y, h) rep(x, w){
        cnt_w = 0, cnt_b = 0;
        if(seen[y][x]) continue;
        seen[y][x] = true;
        bfs(x, y);
        ans += cnt_w * cnt_b;
    }

    cout << ans << endl;

    return 0;
}
