#include<stdio.h>
using namespace std;
const int sss=1<<21;
int n;
int a[1000][1000];
int d[1000],p[10000],color[1000];
int prim(){
	int u,minv;
	for(int i=0;i<n;i++){
		d[i]=sss;
		p[i]=-1;
	}
	d[0]=0;
	while(1){
		minv=sss;
		u=-1;
		for(int i=0;i<n;i++){
			if(minv>d[i]&&color[i]!=1){
				u=i;
				minv=d[i];
			}
		}
		if(u==-1) break;
		color[u]=1;
		for(int v=0;v<n;v++){
			if(color[v]!=1&&a[u][v]!=sss){
				if(d[v]>a[u][v]){
					d[v]=a[u][v];
					p[v]=u;
				}
			}
		}
	}
	int sum=0;
	for(int i=0;i<n;i++){
		if(p[i]!=-1) {
			sum+=a[p[i]][i];
		}
	}
	return sum;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int e;scanf("%d",&e);
			a[i][j]=e==-1?sss:e;
		}
	}
	printf("%d\n",prim());
	return 0;
} 
