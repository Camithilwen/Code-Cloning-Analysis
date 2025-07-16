#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
LL A[1010][1010];
int n,Color[1010][1010];
int N,P[101010],T1[1010*1010],T2[1010*1010],n1,n2;
bool f[101010],vis[1010][1010];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void Pre(){
	for (int i=2;i<=100000;i++){
		if (!f[i]) P[++N]=i;
		for (int j=i+i;j<=100000;j+=i) f[j]=1;
	}
}
void Dfs(int x,int y,int c){
	Color[x][y]=c; vis[x][y]=1;
	for (int k=0;k<4;k++){
		int x1=x+dx[k],y1=y+dy[k];
		if (x1>=1&&x1<=n&&y1>=1&&y1<=n&&!vis[x1][y1])
			Dfs(x1,y1,1-c);
	}
}
void _Num(){
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++)
		if (Color[i][j])
			T1[++n1]=i+j,T2[++n2]=i-j;
	sort(T1+1,T1+n1+1); sort(T2+1,T2+n2+1);
	n1=unique(T1+1,T1+n1+1)-T1-1;
	n2=unique(T2+1,T2+n2+1)-T2-1;
	
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++)
		if (Color[i][j]){
			int p1=lower_bound(T1+1,T1+n1+1,i+j)-T1;
			int p2=lower_bound(T2+1,T2+n2+1,i-j)-T2;
			A[i][j]=(LL)P[p1]*(LL)P[n1+p2];
		}
}
LL gcd(LL a,LL b){
	if (!b) return a;
	return gcd(b,a%b);
}
LL Lcm(LL a,LL b){
	LL g=gcd(a,b);
	return (a/g)*b;
}
int main(){
	scanf("%d",&n);
	if (n==2){
		printf("4 7\n23 10"); return 0;
	}
	Pre(); Dfs(1,1,1); _Num();
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (!Color[i][j]){
		LL g=1;
		for (int k=0;k<4;k++){
			int x1=i+dx[k],y1=j+dy[k];
			if (x1>=1&&x1<=n&&y1>=1&&y1<=n)
				g=Lcm(g,A[x1][y1]);
		}
		A[i][j]=g+1;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) printf("%lld ",A[i][j]);
		printf("\n");
	}	
}