#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,ll>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;

const int INF=1e8;

int minlen(vector<P> A,vector<P> B){
    int res=1e8;
    for(P p:B){
        int a=lower_bound(A.begin(),A.end(),p)-A.begin();
        if(a==A.size())continue;
        if(A.at(a).first!=p.first)continue;
        chmin(res,A.at(a).second-p.second);
    }
    return res;
}

int main() {
    int N;
    cin>>N;
    vector<int> X(N),Y(N),U(N);
    rep(i,N){
        char c;
        cin>>X.at(i)>>Y.at(i)>>c;
        if(c=='U')U.at(i)=0;
        if(c=='R')U.at(i)=1;
        if(c=='D')U.at(i)=2;
        if(c=='L')U.at(i)=3;
    }
    int ans=INF;
    rep(_,4){
        vector<P> UDD(0),DRD(0),UP(0),RI(0);
        rep(i,N){
            if(U.at(i)==2){
                UDD.pb({X.at(i),Y.at(i)});
                DRD.pb({X.at(i)-Y.at(i),Y.at(i)});
            }
            if(U.at(i)==0){
                UP.pb({X.at(i),Y.at(i)});
            }
            if(U.at(i)==1){
                RI.pb({X.at(i)-Y.at(i),Y.at(i)});
            }
        }
        sort(UDD.begin(),UDD.end());
        sort(DRD.begin(),DRD.end());
        chmin(ans,minlen(UDD,UP)*5);
        chmin(ans,minlen(DRD,RI)*10);

        rep(i,N){
            int x=X.at(i),y=Y.at(i);
            X.at(i)=y;
            Y.at(i)=-x;
            U.at(i)=(U.at(i)+1)%4;
        }
    }
    if(ans==INF)cout<<"SAFE"<<endl;
    else cout<<ans<<endl;
}