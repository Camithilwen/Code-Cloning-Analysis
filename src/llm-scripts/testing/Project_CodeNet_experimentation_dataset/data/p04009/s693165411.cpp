#include <bits/stdc++.h>
using namespace std;

const int N=110, M=5e3+300;
int h,w,F[M][M],idh[N][N],idw[N][N];
char mp[N][N]; int stx,sty,s[N][N];
inline int& f(int l,int r,int u,int d) {return F[idh[l][r]][idw[u][d]];}
inline int getarea(int xc1,int xc2,int yc1,int yc2) {
    return s[xc2][yc2]-s[xc1-1][yc2]-s[xc2][yc1-1]+s[xc1-1][yc1-1];
}
inline int calcl(int p,int up,int dn,int l,int r,int u,int d) {
    if(p<=r || p+l>w) return 0;
    up=max(up,d+1); dn=min(dn,h-u);
    if(up>dn) return 0;
    return getarea(up,dn,p,p);
}
inline int calcr(int p,int li,int ri,int l,int r,int u,int d) {
    if(p<=d || p+u>h) return 0;
    li=max(li,r+1); ri=min(ri,w-l);
    if(li>ri) return 0;
    return getarea(p,p,li,ri);
}
int main() {
    cin>>h>>w; 
    for(int i=1;i<=h;i++) cin>>(mp[i]+1);
    for(int i=1;i<=h;i++) 
        for(int j=1;j<=w;j++) {
            if(mp[i][j]=='o') s[i][j]=1;
            if(mp[i][j]=='E') stx=i, sty=j;
            s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+s[i][j];
        }
    for(int l=0,cnt=0;l<=sty;++l)
        for(int r=0;sty+r<=w;++r)
            idh[l][r]=cnt++;
    for(int u=0,cnt=0;u<=stx;++u)
        for(int d=0;d+stx<=h;++d)
            idw[u][d]=cnt++;

    int ans=0;
    for(int l=0;l<=sty;++l)
        for(int r=0;sty+r<=w;++r)
            for(int u=0;u<=stx;++u)
                for(int d=0;d+stx<=h;++d) {
                    int &s=f(l,r,u,d);
                    if(l) s=max(s,f(l-1,r,u,d)+calcl(sty-l,stx-u,stx+d,l-1,r,u,d));
                    if(r) s=max(s,f(l,r-1,u,d)+calcl(sty+r,stx-u,stx+d,l,r-1,u,d));
                    if(u) s=max(s,f(l,r,u-1,d)+calcr(stx-u,sty-l,sty+r,l,r,u-1,d));
                    if(d) s=max(s,f(l,r,u,d-1)+calcr(stx+d,sty-l,sty+r,l,r,u,d-1));
                    ans=max(ans,s);
                }
    cout<<ans<<'\n';
}