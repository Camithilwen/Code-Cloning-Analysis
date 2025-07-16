#include <bits/stdc++.h>
using namespace std;
#define iinf 2000000000
#define linf 1000000000000000000LL
#define ulinf 10000000000000000000ull
#define MOD1 1000000007LL
#define mpr make_pair
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned long UL;
typedef unsigned short US;
typedef pair < int , int > pii;
clock_t __stt;
inline void TStart(){__stt=clock();}
inline void TReport(){printf("\nTaken Time : %.3lf sec\n",(double)(clock()-__stt)/CLOCKS_PER_SEC);}
template < typename T > T MIN(T a,T b){return a<b?a:b;}
template < typename T > T MAX(T a,T b){return a>b?a:b;}
template < typename T > T ABS(T a){return a>0?a:(-a);}
template < typename T > void UMIN(T &a,T b){if(b<a) a=b;}
template < typename T > void UMAX(T &a,T b){if(b>a) a=b;}
int n,m,a[20][20],pc[20][1000000],dp[20][1000000],rv[1000000];
int main(){
    // inputting start
    // 数据结构记得初始化！ n，m别写反！
    int i,j,k,u,v,w;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;++i){
		scanf("%d%d%d",&u,&v,&w);
		--u;--v;
		a[u][v]=a[v][u]=w;
	}
    #ifdef LOCAL
        TStart();
    #endif
    // calculation start
    // 数据结构记得初始化！ n，m别写反！
	for(i=0;i<n;++i) rv[1<<i]=i;
    for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			for(k=0;k<(1<<n);++k){
				if(k&(1<<j)) pc[i][k]+=a[i][j];
			}
		}
	}
	for(i=0;i<n;++i) fill(dp[i],dp[i]+(1<<n),iinf);
	dp[0][1]=0;
	for(j=0;j<(1<<n);++j){
		for(i=0;i<n;++i){
			if(!(j&(1<<i)) || dp[i][j]==iinf) continue;
			int v=dp[i][j],msk=(((1<<n)-1)^j),cst=0;
			for(k=0;k<=msk;){
				UMIN(dp[i][j|k],v+cst);
				int cp=msk;
				while(cp && (cp&(-cp))==(k&(-k))){
					int cv=(k&(-k));
					cst-=pc[rv[cv]][j^(1<<i)];
					k^=cv;
					cp^=cv;
				}
				if(!k && !cp) break;
				int cv=cp&(-cp);
				cst+=pc[rv[cv]][j^(1<<i)];
				k|=cv;
			}
			for(k=0;k<n;++k){
				if(a[i][k] && !(j&(1<<k))){
					UMIN(dp[k][j|(1<<k)],v+pc[k][j^(1<<i)]);
				}
			}
		}
	}
	printf("%d\n",dp[n-1][(1<<n)-1]);
    #ifdef LOCAL
        TReport();
    #endif
    return 0;
}