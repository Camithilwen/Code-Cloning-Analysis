#include<cstdio>
const int N=1e5+9;
int L[17][N],R[17][N],n,t,q,X[N],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",X+i);
	scanf("%d",&t);
	for(int i=1,it=1;i<=n;++i){
		while(it<n&&X[it+1]-X[i]<=t)++it;
		R[0][i]=it;
	}
	for(int i=n,it=n;i;--i){
		while(it>1&&X[i]-X[it-1]<=t)--it;
		L[0][i]=it;
	}
	for(int i=1;i<17;++i)
	for(int j=1;j<=n;++j)
	R[i][j]=R[i-1][R[i-1][j]],L[i][j]=L[i-1][L[i-1][j]];
	for(scanf("%d",&q);q--;printf("%d\n",ans)){
		int x,y;ans=1;
		scanf("%d%d",&x,&y);
		if(x<=y){
			for(int i=16;~i;--i)
			if(R[i][x]<y)ans+=1<<i,x=R[i][x];
		}else{
			for(int i=16;~i;--i)
			if(L[i][x]>y)ans+=1<<i,x=L[i][x];
		}
	}
	return 0;
}