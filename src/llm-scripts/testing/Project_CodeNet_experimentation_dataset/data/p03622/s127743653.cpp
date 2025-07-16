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
const int mod=998244353;
il int ad(int x,int y){return x+y>=mod?x+y-mod:x+y;}
il int sub(int x,int y){return ad(x,mod-y);}
il int mul(int x,int y){return (ll)x*y%mod;}
il void inc(int &x,int y){x=ad(x,y);}
il void inc2(int &x,int y){x=mul(x,y);}
il int qm(int x,int y=mod-2){int ret=1;while(y){if(y&1) ret=mul(x,ret);x=mul(x,x);y>>=1;}return ret;}
template<class ...Args>il int ad(const int a,const int b,const Args &...args) {return ad(ad(a,b),args...);}
template<class ...Args>il int mul(const int a,const int b,const Args &...args) {return mul(mul(a,b),args...);}
}
using namespace Modulo;
namespace Miracle{
const int N=1e6+5;
int n,m; 
int jie[N],inv[N];
int C(int n,int m){
	return mul(jie[n],inv[m],inv[n-m]);
}
int main(){
    rd(n);rd(m);
    jie[0]=1;
    int lim=2*max(n,m);
    for(reg i=1;i<=lim;++i) jie[i]=mul(jie[i-1],i);
	inv[lim]=qm(jie[lim]);
	for(reg i=lim-1;i>=0;--i) inv[i]=mul(inv[i+1],i+1);
	int d=min(n,m);
	int sum=0;
	for(reg i=1;i<=d;++i){
		inc(sum,mul(C(2*i,i),C(n+m-2*i,n-i)));
	}
	inc2(sum,qm(2));
	inc(sum,mul(max(n,m),C(n+m,n)));
	int ans=mul(sum,qm(C(n+m,n)));
	cout<<ans;
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