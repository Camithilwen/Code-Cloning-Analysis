#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int po[22];

int dfs(int i,int dif,int L){
    if(i==L/2){
        return dif==0;
    }

    int u=po[L-1-i]-po[i];

    int x;
    if(dif>=0){
        x=(dif+u-1)/u;
    }
    else{
        x=dif/u;
    }

    int ret=0;
    for(int uku=0;uku<2;uku++,x--){
        if(x<-9||9<x)continue;
        int tmp=dfs(i+1,dif-u*x,L);

        int k=10-abs(x);
        if(i==0&&x>=0)k--;
        ret+=tmp*k;
    }

    return ret;
}

signed main(){
    po[0]=1;
    for(int i=1;i<22;i++)po[i]=po[i-1]*10;
    int D;cin>>D;
    int ans=0;
    for(int i=2;i<=18;i++){
        int w;
        if(i&1)w=10;
        else w=1;

        ans+=w*dfs(0,D,i);
    }
    cout<<ans<<endl;
    return 0;
}
