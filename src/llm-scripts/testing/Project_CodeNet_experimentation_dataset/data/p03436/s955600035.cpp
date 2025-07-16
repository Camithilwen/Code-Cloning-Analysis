#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rev(i, n) for(int i = (int)(n - 1); i >= 0; i--)
#define rev1(i, n) for(int i = (int)(n); i > 0; i--)
#define pb push_back
#define all(v) ((v).begin(), (v).end())
using ll = long long;
using P = pair<int, int>;
/* ------------------------------------------------ */
ll fact(int i) {       //階乗
    if (i == 0) return 1;
    return (fact(i - 1)) * i;
}
ll gcd(ll a, ll b) {        //最大公約数
    if(b == 0) return a;
    return gcd(b, a % b); 
}
ll lcm(ll a, ll b) {      //最小公倍数
    return a * b / gcd(a, b);
}
int keta(ll n) {        //桁数を求める
    if(n == 0) return 1;
    int count = 0;
    while(n != 0) {
        n /= 10;
        count++;
    }
    return count;
}
ll ketasum(ll n) {    //各桁の和
    ll sum = 0;
    while(n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
/* ------------------------------------------------ */
int main() {
    int h,w;
    cin >> h >> w;
    char s[55][55];
    rep(i, h) {
        rep(j, w) cin >> s[i][j];
    }
    int dist[55][55];
    rep(i, h) {
        rep(j, w) dist[i][j] = -1;
    }
    dist[0][0] = 1;
    int f[]={0,1,0,-1};
    int g[]={1,0,-1,0};
    queue<P> que;
    que.push({0,0});
    while(!que.empty()) {
        P p = que.front();
        que.pop();
        rep(i, 4) {
            int x = p.first + f[i],y = p.second + g[i];
            if(x > h-1 || x < 0 || y > w-1 || y < 0) continue;
            if(dist[x][y] == -1 && s[x][y] == '.'){
                dist[x][y] = dist[p.first][p.second]+1;
                que.push({x,y});
            }
        }
    }
    if(dist[h-1][w-1]==-1) {
        cout << -1 << endl;
        return 0;
    }
    int ans = h*w - dist[h - 1][w - 1];
    rep(i, h) {
        rep(j, w) if(s[i][j] == '#') ans--;
    }
    cout << ans << endl;
    return 0;
}