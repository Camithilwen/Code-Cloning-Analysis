#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define MN 505
using namespace std;
typedef long long ll;
int n,pr[MN<<2],tt;bool p[MN*MN];
ll a[MN][MN];
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};
int main(){
	scanf("%d",&n);
	for(int i=2;i<=1e5;i++){
		if(!p[i]){
			pr[++tt]=i;
			if(tt>=4*n)break;
		}
		for(int j=1;j<=tt;j++){
			if(i*pr[j]>1e5)break;
			p[i*pr[j]]=1;
			if(i%pr[j]==0)break;
		}
	}ll tt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((i+j)%2==0){
				a[i][j]=1ll*pr[i+j>>1]*pr[(i-j)/2+n];
			}else {
				a[i][j]=1ll*pr[i+j>>1]*pr[(i+j+1)>>1];
				if(i-j<0)a[i][j]*=1ll*pr[(i-j)/2+n]*pr[(i-j-1)/2+n];
				else a[i][j]*=1ll*pr[(i-j)/2+n]*pr[(i-j+1)/2+n];a[i][j]++;
				tt=max(a[i][j],tt);
			}//printf("%lld\n",tt);
/*	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=0;k<4;k++){
		int tx=i+dx[k],ty=j+dy[k];
		if(tx>=1&&tx<=n&&ty>=1&&ty<=n){
			if(max(a[i][j],a[tx][ty])%min(a[i][j],a[tx][ty])!=1)printf("%d %d %d %d\n",i,j,tx,ty);
		}
	}*/
	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)printf("%lld ",a[i][j]);puts("");}
}
