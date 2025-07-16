#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

int main() {
    int n,m,q;cin>>n>>m>>q;
    int a[n][n];
    
    rep(i,n)rep(j,n)a[i][j]=0;
    
    int tmp_r,tmp_l;
    rep(i,m){
        cin>>tmp_l>>tmp_r;
        --tmp_l,--tmp_r;
        ++a[tmp_l][tmp_r];
    }

    int b[n][n];
    rep(i,n)rep(j,n)b[i][j]=a[i][j];
    rep(i,n)rep(j,n-1)b[i][j+1]+=b[i][j];
    
    int ql,qr;
    rep(i,q){
        int ans = 0;
        cin>>ql>>qr;
        --ql,--qr;
      ans = b[qr][qr];
        REP(j,ql,qr)ans+=b[j][qr];
//      if(ql!=0)REP(j,ql,qr+1)ans-=b[ql-1][j];

      cout<<ans<<endl;
    }
 	return 0;
}