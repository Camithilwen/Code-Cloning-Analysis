#include <bits/stdc++.h>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,Q,K,A,B;
string S;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
typedef pair<ll, ll> P;
const ll INF = (1LL<<58);

template<class T> bool chmin(T &a, const T &b){
    if(a > b) {a = b; return true;}
    else return false;
}
template<class T> bool chmax(T &a, const T &b){
    if(a < b) {a = b; return true;}
    else return false;
}

ll check(set<P> &s){
    ll last = -INF * 2, res = INF;
    for(P p : s){
        if(p.se){
            chmin(res, p.fi - last);
        }else{
            last = p.fi;
        }
    }
    return res;
}

int main() {
    const ll t2 = 200000;
    typedef vector<vector<set<P> > > mats;
    map<char, int> ctoi = {{'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};
    cin>>N;
    vec x(N), y(N), u(N);
    //0 : up
    mats memo(6, vector<set<P>>(400001));
    rep(i,N) {
        char c;
        cin>>x[i]>>y[i]>>c;
        u[i] = ctoi[c];
        if(u[i] < 2){
            memo[u[i]][u[i] ? y[i] : x[i]].emplace(u[i] ? x[i] : y[i], 0);
            memo[u[i] + 2][y[i] - x[i] + t2].emplace(y[i] + x[i], 0);
        }else{
            memo[u[i] - 2][u[i] - 2 ? y[i] : x[i]].emplace(u[i] - 2 ? x[i] : y[i], 1);
            memo[5 - u[i]][y[i] - x[i] + t2].emplace(y[i] + x[i], 1);
        }
        if(u[i] == 0){
            memo[4][y[i] + x[i]].emplace(y[i] - x[i], 0);
        }else if(u[i] == 1){
            memo[4][y[i] + x[i]].emplace(y[i] - x[i], 1);
        }else if(u[i] == 2){
            memo[5][y[i] + x[i]].emplace(y[i] - x[i], 1);
        }else{
            memo[5][y[i] + x[i]].emplace(y[i] - x[i], 0);
        }
    }
    ll res = INF;
    rep(i,6){
        rep(j, 400001){
            chmin(res, check(memo[i][j]));
        }
    }
    if(res == INF) cout<<"SAFE"<<endl;
    else cout<<res * 5<<endl;
}
