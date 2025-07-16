#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod=1000000007;
const ll INF=1e15;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

vec chikan(vec X, vec M){
    vec ret(M.size());
    for(int i=0;i<M.size();i++) {
        ret.at(i)=M.at(X.at(i));
    }
    return ret;
}

vec bekic(vec X, ll n){
    vec ret(X.size());
    rep(i,X.size()) ret.at(i)=i;
    
    while(n>0){
        if(n%2) ret=chikan(ret,X);
        X=chikan(X,X);
        n/=2;
    }
    return ret;
}

int main(){
    ll N; cin>>N;
    vec x(N);
    rep(i,N) cin>>x.at(i);
    ll M,K; cin>>M>>K;
    vec a(M);
    rep(i,M) cin>>a.at(i);
    rep(i,M) a.at(i)--;

    vec d(N);
    REP(i,1,N) d.at(i)=x.at(i)-x.at(i-1);
    vec P(N);
    rep(i,N) P.at(i)=i;
    rep(i,M) swap(P.at(a.at(i)),P.at(a.at(i)+1));
    P=bekic(P,K);
    d=chikan(P,d);
    d.at(0)=x.at(0);
    rep(i,N-1) d.at(i+1)+=d.at(i);
    rep(i,N) cout<<d.at(i)<<endl;

}