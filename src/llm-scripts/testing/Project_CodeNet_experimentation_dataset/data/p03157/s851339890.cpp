#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;


#define rep(i,n) for(ll (i)=0; (i)<(ll)(n); (i)++)
#define frep(i,m,n) for(ll (i)=(m); (i)<=(ll)(n); (i)++)
#define rrep(i,n) for(ll (i)=(n)-1; (i)>-1; (i)--)
#define frrep(i,m,n) for(ll (i)=(n); (i)>(ll)(m); (i)--)
#define ALL(x) (x).begin(), (x).end()

const ll INF = 100100100100100100;
const ll MOD = 1000000007;

// get abs
ll my_abs(ll a);
// a^n
ll a_n(ll a, ll n);
// get gcd
ll my_gcd(ll a, ll b);
// a^(-1) % MOD 
ll inv(ll a);
// (a+b+c)%MOD
ll madd(ll a, ll b, ll c);
// (a-b)%MOD
ll msub(ll a, ll b);
// (a*b*c)%MOD
ll mtime(ll a, ll b, ll c);


int main() {
    ll h, w, ans = 0; cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<vector<bool>> used(h, vector<bool>(w, false));

    rep(i, h) {
        rep(j, w) {
            // スタート地点
            if(s[i][j] == '.' && !used[i][j]) {
                ll wh = 0, bl = 0; // 白と黒
                wh++;
                queue<P> que;
                que.push(make_pair(i, j));
                used[i][j] = true;
                // 幅優先
                while(!que.empty()) {
                    P t = que.front();
                    que.pop();
                    ll x = t.first, y = t.second;
                    if(x > 0) if(!used[x-1][y] && s[x][y] != s[x-1][y]) {
                        used[x-1][y] = true;
                        que.push(make_pair(x-1, y));
                        if(s[x-1][y] == '.') wh++;
                        else bl++;
                    }
                    if(x < h-1) if(!used[x+1][y] && s[x][y] != s[x+1][y]) {
                        used[x+1][y] = true;
                        que.push(make_pair(x+1, y));
                        if(s[x+1][y] == '.') wh++;
                        else bl++;
                    }
                    if(y > 0) if(!used[x][y-1] && s[x][y] != s[x][y-1]) {
                        used[x][y-1] = true;
                        que.push(make_pair(x, y-1));
                        if(s[x][y-1] == '.') wh++;
                        else bl++;
                    }
                    if(y < w-1) if(!used[x][y+1] && s[x][y] != s[x][y+1]) {
                        used[x][y+1] = true;
                        que.push(make_pair(x, y+1));
                        if(s[x][y+1] == '.') wh++;
                        else bl++;
                    }
                }
                ans += bl*wh;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

ll my_abs(ll a) {
    if(a >= 0) return a;
    else return -1 *a;
}

ll a_n(ll a, ll n) { 
    if(n == 0) return 1;
    
    ll ret = a, count = 1;
    while(count * 2 < n) {
        ret *= ret;
        count *= 2;
    }
    if(count == n) return ret;
    else return (ret * a_n(a, n-count));
}

ll my_gcd(ll a, ll b) {
    if(b == 0) return a;
    return my_gcd(b, a%b);
}

ll inv(ll a) {
    return a_n(a, MOD-2);
}

ll madd(ll a, ll b, ll c) {
    ll ret = (a+b) % MOD;
    return (ret+c) % MOD;
}

ll msub(ll a, ll b) {
    if(a < b) return (a-b+MOD) % MOD;
    else return (a-b) % MOD;
}

ll mtime(ll a, ll b, ll c) {
    ll ret = (a*b) % MOD;
    return (ret*c) % MOD;
}
