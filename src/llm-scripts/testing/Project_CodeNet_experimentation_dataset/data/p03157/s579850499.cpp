#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

ll d[401][401];

const ll MAXN=200001;

ll par[MAXN];
ll rnk[MAXN];
ll Size[MAXN];

vec D(MAXN,-1);

ll Co[MAXN][2];

void shoki(){
    for(ll i=0;i<MAXN;i++) {par[i]=i; rnk[i]=0; Size[i]=1;}
}

ll sch(ll x){
    if(par[x]==x) return x;
    else return par[x]=sch(par[x]);
}

void con(ll A,ll B){
    A=sch(A);
    B=sch(B);
    if(A==B) return;
    if(rnk[A]>rnk[B]) swap(A,B);
    par[A]=B;
    Size[B]+=Size[A];
    Size[A]=Size[B];
    if(rnk[A]==rnk[B]) rnk[B]++;

    return;
}

ll is_size(ll k){
    return Size[sch(k)];
}

bool same(ll A,ll B){
    return sch(A)==sch(B);
}

int main(){
    shoki();
    rep(i,401) rep(j,401) d[i][j]=INF;
    ll H,W; cin>>H>>W;
    rep(i,H){
        string S; cin>>S;
        rep(j,W){
            if(S.at(j)=='#') d[i][j]=1;
            else d[i][j]=0;
            D.at(i*450+j)=d[i][j];
        }
    }

    rep(i,H) rep(j,W){
        if(i!=H-1){
            if(d[i][j]!=d[i+1][j]) con(i*450+j,(i+1)*450+j); 
        }

        if(j!=W-1){
            if(d[i][j]!=d[i][j+1]) con(i*450+j,i*450+j+1); 
        }
    }
    rep(i,H) rep(j,W){
        ll x=i*450+j;
        //cout<<sch(x)<<endl;
        Co[sch(x)][D.at(x)]++;
    }
    ll ans=0;
    rep(i,H) rep(j,W){
        ll x=i*450+j;
       // cout<<Co[x][0]<<' '<<Co[x][1]<<endl;
        ans+=Co[x][0]*Co[x][1];
    }
    cout<<ans<<endl;

    




}