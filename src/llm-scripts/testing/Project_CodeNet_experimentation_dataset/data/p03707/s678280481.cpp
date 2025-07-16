#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main(){
    cin>>N>>M>>Q;
    vector<string> grid(N);
    rep(i,N) cin>>grid[i];
    mat edge(N, vec(M, 0)), num(N + 1, vec(M + 1, 0)), addr(N, vec(M,0)), addc(N, vec(M,0));
    rep(i,N){
        rep(j,M){
            bool blue = grid[i][j] == '1';
            if(i > 0) {
                edge[i][j] += edge[i-1][j] + (blue && grid[i-1][j] == '1');
                addc[i][j] = addc[i-1][j] + (blue && grid[i-1][j] == '1');
            }
            if(j > 0) {
                edge[i][j] += edge[i][j-1] + (blue && grid[i][j-1] == '1');
                addr[i][j] = addr[i][j-1] + (blue && grid[i][j-1] == '1');
            }
            if(i > 0 && j > 0) edge[i][j] -= edge[i-1][j-1];
            num[i+1][j+1] = num[i][j+1] + num[i+1][j] - num[i][j] + blue;
        }
    }
    vec x(2), y(2);
    rep(i,Q){
        rep(j,2) cin>>x[j]>>y[j];
        --x[0], --y[0];
        ll res = 0;
        rep(j,2) rep(k,2) res += (j^k ? -1 : 1) * num[x[j]][y[k]];
        --x[1], --y[1];
        rep(j,2) rep(k,2) res += (j^k ? 1 : -1) * edge[x[j]][y[k]];
        res -= addr[x[0]][y[1]] - addr[x[0]][y[0]];
        res -= addc[x[1]][y[0]] - addc[x[0]][y[0]];
        cout<<res<<endl;
    }
    /*rep(i,N){
        rep(j,M) cout<<edge[i][j]<<' ';
        cout<<endl;
    }*/
}