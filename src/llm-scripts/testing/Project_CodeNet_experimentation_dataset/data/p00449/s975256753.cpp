#include<stdio.h>
#define INF 100000001
int n,m;
int i,j,k;
int t[100][100];
int r,a,b,c;
bool used[100];
int d[100];
int ans;

int min(int a,int b){
	if(a<=b)return a;
	else return b;
}

int solve(int a,int b){
	int v;
	while(1){
		v=-1;
		for(k=0;k<n;k++)if(!used[k]&&(v==-1||d[k]<d[v]))v=k;
		if(d[v]==INF||v==-1)break;
		used[v]=true;
		for(k=0;k<n;k++){
			if(t[v][k]!=INF)d[k]=min(d[k],d[v]+t[v][k]);
		}
	}
	return d[b];
}
int main(){
	while(1){
		scanf("%d %d",&n,&m);
		if(n==0&&m==0)return 0;
		for(i=0;i<n;i++)for(j=0;j<n;j++)t[i][j]=INF;
		for(i=0;i<m;i++){
			scanf("%d",&r);
			if(r==1){
				scanf("%d %d %d",&a,&b,&c);
				t[a-1][b-1]=min(t[a-1][b-1],c);
				t[b-1][a-1]=min(t[b-1][a-1],c);
			}
			if(r==0){
				scanf("%d %d",&a,&b);
				for(j=0;j<n;j++){
					used[j]=false;
					d[j]=INF;
				}
				d[a-1]=0;
				ans=solve(a-1,b-1);
				if(ans==INF)printf("-1\n");
				else printf("%d\n",ans);
			}
		}
	}
}