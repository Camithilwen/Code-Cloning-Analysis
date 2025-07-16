#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;
struct graph{
	int h[360010],nex[27000010],to[27000010],col[360010],M;
	bool v[360010];
	graph(){
		M=0;
		memset(h,0,sizeof(h));
		memset(v,0,sizeof(v));
		memset(col,0,sizeof(col));
	}
	void ins(int a,int b){
		M++;
		to[M]=b;
		nex[M]=h[a];
		h[a]=M;
	}
	void add(int a,int b){
		ins(a,b);
		ins(b,a);
	}
	void dfs(int x,int c){
		col[x]=c;
		v[x]=1;
		int i,j;
		for(i=h[x];i;i=nex[i]){
			if(!v[to[i]]){
				v[to[i]]=1;
				for(j=h[to[i]];j;j=nex[j]){
					if(!v[to[j]])dfs(to[j],c);
				}
			}
		}
	}
}g[2];
int n;
int p(int i,int j){return i*2*n+j+1;}
bool sq(int x){
	double d=sqrt(x);
	return fabs(d-round(d))<1e-6;
}
void build(int f,int x,int y){
	if(y>=2*n)return;
	int i,j;
	for(i=0;i+x<2*n;i++){
		for(j=0;j+y<2*n;j++)g[f].add(p(i,j),p(i+x,j+y));
	}
	for(i=0;i+x<2*n;i++){
		for(j=2*n-1;j-y>=0;j--)g[f].add(p(i,j),p(i+x,j-y));
	}
}
struct pr{
	int x,y;
	pr(int a=0,int b=0){x=a;y=b;}
};
vector<pr>v[4];
int main(){
	int i,j,d1,d2;
	scanf("%d%d%d",&n,&d1,&d2);
	for(i=0;i<2*n&&i*i<=d1;i++){
		if(sq(d1-i*i))build(0,i,round(sqrt(d1-i*i)));
	}
	for(i=0;i<2*n&&i*i<=d2;i++){
		if(sq(d2-i*i))build(1,i,round(sqrt(d2-i*i)));
	}
	for(i=1;i<=4*n*n;i++){
		if(!g[0].v[i])g[0].dfs(i,1);
		if(!g[1].v[i])g[1].dfs(i,2);
	}
	for(i=0;i<2*n;i++){
		for(j=0;j<2*n;j++)v[g[0].col[p(i,j)]|g[1].col[p(i,j)]].push_back(pr(i,j));
	}
	for(i=0;i<4;i++){
		if((int)v[i].size()>=n*n){
			for(j=0;j<n*n;j++)printf("%d %d\n",v[i][j].x,v[i][j].y);
			break;
		}
	}
}