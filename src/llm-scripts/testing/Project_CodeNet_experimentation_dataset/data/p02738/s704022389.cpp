#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > pii;
typedef long long LL;
#define mpr make_pair
#define FS first
#define SC second
#define PB push_back
template < typename T > T MAX(T a,T b){return (a>b)?a:b;}
template < typename T > T MIN(T a,T b){return (a<b)?a:b;}
template < typename T > void UMAX(T &a,T b){a=(a>b?a:b);}
template < typename T > void UMIN(T &a,T b){a=(a<b?a:b);}
LL readint(){
	char c=getchar();
	LL ret=0ll;
	while(!(c>='0' && c<='9')) c=getchar();
	while(c>='0' && c<='9'){
		ret=ret*10ll+(LL)(c-'0');
		c=getchar();
	}
	return ret;
}
void putint(LL v){
	if(!v){
		putchar('0');
		return;
	}
	if(v>=10ll) putint(v/10ll);
	putchar('0'+(v%10ll));
}
int n,M,fac[10005],ifac[10005];
int powM(int V,int T){
	int R=1;
	while(T){
		if(T&1) R=(LL)R*(LL)V%(LL)M;
		T>>=1;
		V=(LL)V*(LL)V%(LL)M;
	}
	return R;
}
int main(){
	int i,j,k;
	scanf("%d%d",&n,&M);
	fac[0]=1;
	for(i=1;i<=10000;++i){
		fac[i]=(LL)fac[i-1]*(LL)i%(LL)M;
	}
	ifac[10000]=powM(fac[10000],M-2);
	for(i=9999;i>=0;--i){
		ifac[i]=(LL)ifac[i+1]*(LL)(i+1)%(LL)M;
	}
	int res=0;
	for(i=0;i<=n;++i){// # of 3
		for(j=0;i+j<=n;++j){// # of 2
			int R=(LL)fac[n*3]*(LL)powM(ifac[2],j)%(LL)M*(LL)powM(ifac[3],i)%(LL)M;
			R=(LL)R*(LL)ifac[i]%(LL)M*(LL)ifac[j]%(LL)M*(LL)ifac[n*3-i*3-j*2]%(LL)M;
			R=(LL)R*(LL)powM(2,i)%(LL)M;
			res+=R;
			if(res>=M) res-=M;
		}
	}
	printf("%d\n",res);
	return 0;
}