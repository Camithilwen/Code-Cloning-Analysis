#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Mid ((l+r)/2)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define drep(i,a,b) for(int i=(a);i>=(b);--i)
#define file(a) freopen(#a".in","r",stdin),freopen(#a".out","w",stdout);
const int maxn=2e3+5,mod=1e9+7,inf=0x3f3f3f3f;
int n,m,Q,K,T;
int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}char c[maxn];
bool a[maxn][maxn];
bool b[maxn][maxn];
int pre[maxn][maxn];
int stk[maxn],top;
int h[maxn];
signed main(){
    //file(a);
    n=read();m=read();
    rep(i,1,n){
        scanf("%s",c+1);
        rep(j,1,m)a[i][j]=(c[j]=='.');
    }
    rep(i,1,n-1)rep(j,1,m-1){
        int cnt=0;
        rep(ii,i,i+1)rep(jj,j,j+1)cnt+=a[ii][jj];
        b[i][j]=(!(cnt&1));
    }
    rep(j,1,m-1){
        int now=1;
        rep(i,1,n-1){
            if(b[i][j]!=b[now][j])now=i;
            pre[i][j]=now;
        }
    }int ans=0;
    rep(i,1,n-1){
        rep(j,1,m-1)h[j]=i-pre[i][j]+1;
        stk[0]=0;stk[top=1]=1;
        rep(j,2,m){
            if(b[i][j]!=b[i][j-1]||j>=m){
                while(top){
                    int x=j-stk[top-1]-1,y=h[stk[top]];
                    ans=max(ans,(x+1)*(y+1));--top;
                }stk[0]=j-1,stk[top=1]=j;continue;
            }
            while(top&&h[stk[top]]>=h[j]){
                int x=j-stk[top-1]-1,y=h[stk[top]];
                ans=max(ans,(x+1)*(y+1));--top;
            }stk[++top]=j;
        }
    }printf("%d\n",(max(ans,max(n,m))));


    return 0;
}
