#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%mod

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

ll N,M;
ll d[301][301];
bool used[301];
ll Start[301];

ll Solve(ll x){
    if(!used[d[x][Start[x]]]) return d[x][Start[x]];
    Start[x]++;
    return Solve(x);
}

ll SOLVE(){
    vec kari(M+1,0);
    rep(i,N) kari[Solve(i)]++;
    ll MAX=-INF, basho=-1;
    rep(i,M) if(kari[i]>MAX){
        MAX=kari[i];
        basho=i;
    }
    //rep(i,M) cout<<kari[i]<<' ';
    //cout<<endl;
    //cout<<MAX<<' '<<basho+1<<endl;
    used[basho]=true;
    return MAX;
}
ll MAIN(){
    if(M==1) return N;
    ll ret=INF;
    rep(i,M-1) {
        //cout<<i<<':';
        ll K=SOLVE();
        ret=min(ret,K);
    }
    return ret;
}
int main(){
    cin>>N>>M;
    rep(i,N) rep(j,M) {cin>>d[i][j]; d[i][j]--;}
    cout<<MAIN()<<endl;

}