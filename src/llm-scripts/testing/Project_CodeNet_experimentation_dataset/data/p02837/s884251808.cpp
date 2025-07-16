#include<bits/stdc++.h>
using namespace std;

#define rep(i,n)  for(int i=0;i<n;++i)
#define per(i,n)  for(int i=n-1;i>=0;--i)
#define sc1(a)  scanf("%d",&a)
#define sc2(a,b)  scanf("%d %d",&a,&b)
#define sc3(a,b,c)  scanf("%d %d %d",&a,&b,&c)


int main(){
    int mod=1000000007;
    int n,a,ans=0;
    sc1(n);
    int w[15][14][2];
    rep(i,15) rep(j,14) rep(k,2) w[i][j][k]=0;
    rep(i,n) {
        sc1(a);
        rep(j,a) sc2(w[i][j][0],w[i][j][1]);
    }
    rep(i,pow(2,n)) {
        if (i==0) continue;
        int x=i;
        int l[15]={0};
        rep(j,n) {
            if (x&1) l[j]=1;
            x=x>>1;
        }
        int f=1;
        rep(j,n) {
            if (l[j]) {
                rep(k,14) if (w[j][k][0]>0 && l[w[j][k][0]-1]!=w[j][k][1]) f=0;
            }
        }
        int cnt=0;
        if (f) {
            rep(j,n) cnt+=l[j];
            ans=max(ans,cnt);
        }
    }
    printf("%d\n",ans);
    return 0;
}
