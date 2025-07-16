#include<bits/stdc++.h>
#define reg register int
#define il inline
#define fi first
#define se second
#define mk(a,b) make_pair(a,b)
#define numb (ch^'0')
#define pb push_back
#define solid const auto &
#define enter cout<<endl
#define pii pair<int,int>
using namespace std;
typedef long long ll;
template<class T>il void rd(T &x){
    char ch;x=0;bool fl=false;while(!isdigit(ch=getchar()))(ch=='-')&&(fl=true);
    for(x=numb;isdigit(ch=getchar());x=x*10+numb);(fl==true)&&(x=-x);}
template<class T>il void output(T x){if(x/10)output(x/10);putchar(x%10+'0');}
template<class T>il void ot(T x){if(x<0) putchar('-'),x=-x;output(x);putchar(' ');}
template<class T>il void prt(T a[],int st,int nd){for(reg i=st;i<=nd;++i) ot(a[i]);putchar('\n');}
namespace Modulo{
const int mod=1e9+7;
int ad(int x,int y){return (x+y)>=mod?x+y-mod:x+y;}
void inc(int &x,int y){x=ad(x,y);}
int mul(int x,int y){return (ll)x*y%mod;}
void inc2(int &x,int y){x=mul(x,y);}
int qm(int x,int y=mod-2){int ret=1;while(y){if(y&1) ret=mul(x,ret);x=mul(x,x);y>>=1;}return ret;}
}
using namespace Modulo;
namespace Miracle{
const int N=2002;
const int M=4000000+5+N+N;
int n,k;
int f[2][N];
int jie[M],inv[M];
int C(int n,int m){
    if(n<0||m<0||n<m) return 0;
    return mul(jie[n],mul(inv[m],inv[n-m]));
}
int main(){
    rd(n);rd(k);
    if(k==1){
        puts("1");return 0;
    }
    int lim=n*k+n+n;
    jie[0]=1;
    for(reg i=1;i<=lim;++i) jie[i]=mul(jie[i-1],i);
    inv[lim]=qm(jie[lim]);
    for(reg i=lim-1;i>=0;--i) inv[i]=mul(inv[i+1],i+1);
    int tmp=0;
    f[0][0]=1;
    for(reg i=2*n;i>=1;--i){
        tmp^=1;
        memset(f[tmp],0,sizeof f[tmp]);
        int re=2*n-i;
        for(reg j=0;j<=min(re,n);++j){
            if(!f[tmp^1][j]) continue;
            int le=re-j;
            if(le+1<=j) f[tmp][j]=ad(f[tmp][j],f[tmp^1][j]);
            if(j!=n){
                f[tmp][j+1]=ad(f[tmp][j+1],mul(f[tmp^1][j],C(k-2+le+j*(k-1),le+j*(k-1))));
            }
        }
    }
    ll ans=mul(f[tmp][n],jie[n]);
    ot(ans);
    return 0;
}

}
signed main(){
    Miracle::main();
    return 0;
}

/*
   Author: *Miracle*
*/