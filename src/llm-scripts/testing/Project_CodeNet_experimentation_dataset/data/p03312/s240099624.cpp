#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
const int N=200005;
 
inline int read(){
    int x=0; char ch=getchar();
    for(;!isdigit(ch);ch=getchar());
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
    return x;
}
 
int n,px,py;
ll a[N],ans=1e18,tot,now,mx,mn;
 
inline void update(){
    if(now<mn) mn=now;
    else if(now>mx) mx=now;
}
 
inline void solve(){
    for(int i=1;i<=n;i++){
        while(px<i&&a[px+1]*2ll<=a[i]) px++;
        while(py<n&&a[py+1]*2ll<=tot+a[i]) py++;
         
        for(int u=px+1;u>=px;u--)
            for(int v=py+1;v>=py;v--){
                mx=mn=a[u];
                 
                now=a[i]-a[u],update();
                now=a[v]-a[i],update();
                now=tot-a[v],update();
                 
                ans=min(ans,mx-mn);
            }
    }
}
 
int main(){
    n=read();
    for(int i=1;i<=n;i++) a[i]=a[i-1]+(ll)read();
    a[n+1]=a[n+2]=tot=a[n];
    solve(),printf("%lld\n",ans);
    return 0;
}