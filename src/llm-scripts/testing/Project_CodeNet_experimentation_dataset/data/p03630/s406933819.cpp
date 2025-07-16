#include<bits/stdc++.h>
#define inf 1000000000
#define N 5005
using namespace std;
char s[N];
int n,m,l[N][N],a[N][N],up[N][N],r[N][N],R[N][N],L[N][N];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=m;j++){
			if (s[j]=='#') a[i][j]=1;
			else a[i][j]=0;
		}
	}
	int ans=max(n,m);n--;m--;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) a[i][j]=a[i][j]^a[i][j+1]^a[i+1][j]^a[i+1][j+1];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i][j]) l[i][j]=0;
			else l[i][j]=l[i][j-1]+1;
		}
		for (int j=m;j;j--){
			if (a[i][j]) r[i][j]=0;
			else r[i][j]=r[i][j+1]+1;
		}
	}
	for (int i=1;i<=m;i++) L[0][i]=R[0][i]=inf;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i][j]) up[i][j]=0,L[i][j]=R[i][j]=inf;
			else {
				up[i][j]=up[i-1][j]+1;
				L[i][j]=min(l[i][j],L[i-1][j]);
				R[i][j]=min(R[i-1][j],r[i][j]);
			}
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (!a[i][j]) ans=max(ans,(up[i][j]+1)*(R[i][j]+L[i][j]));
	printf("%d\n",ans);
	return 0;
}