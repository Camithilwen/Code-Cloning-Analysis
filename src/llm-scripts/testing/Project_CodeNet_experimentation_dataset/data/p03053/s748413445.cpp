#include <bits/stdc++.h>
#define owo(i,a, b) for(int i=(a);i<(b); ++i)
#define uwu(i,a, b) for(int i=(a)-1; i>=(b); --i)
#define senpai push_back
#define ttgl pair<int, int>
#define ayaya cout<<"ayaya~"<<endl
 
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gpu_hash_map<int, int> mp;*/
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
const ll root = 62;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll binpow(ll a,ll b){ll res=1;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modInv(ll a){return binpow(a, MOD-2);}
const double PI = acos(-1);
const double eps = -1e6;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 1001;
int board[mxN][mxN];
int dist[mxN][mxN];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int h, w;
bool inside(int x, int y) {
    return x>=0&&x<h&&y>=0&&y<w;
}
int main() {
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0)->sync_with_stdio(0);
    cin>>h>>w;
    string s;
    queue<ttgl> Q;
    memset(dist, INF, sizeof(dist));
    owo(i, 0, h) {
            cin>>s;
        owo(j, 0, w) {
            board[i][j] = s[j]=='#';
            if(s[j]=='#') {
                Q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    int ans = 0;
    while(!Q.empty()) {
        auto p = Q.front();
        Q.pop();
        ans = dist[p.first][p.second];
        owo(d, 0, 4) {
            if(inside(p.first+dx[d], p.second+dy[d])) {
                if(dist[p.first+dx[d]][p.second+dy[d]]==INF) {
                    dist[p.first+dx[d]][p.second+dy[d]] = dist[p.first][p.second]+1;
                    Q.push({p.first+dx[d], p.second+dy[d]});
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}