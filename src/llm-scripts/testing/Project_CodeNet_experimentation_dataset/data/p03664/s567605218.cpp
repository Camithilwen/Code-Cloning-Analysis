#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 17;
const int L = 32775;
const int INF = 2e+9;

int f[L][N],val[L];
int n,m;
struct edge{
	int x,y,l;
}e[N*N];
int d[N][N];

int main(){
	n=get();m=get();
	int sum=0;
	fo(i,1,m){
		e[i].x=get();e[i].y=get();e[i].l=get();
		sum+=e[i].l;
		d[e[i].x][e[i].y]=d[e[i].y][e[i].x]=e[i].l;
	}
	fo(t,1,(1<<n)-1){
		fo(i,1,m)
		if (((1<<(e[i].x-1))&t)>0&&((1<<(e[i].y-1))&t)>0)val[t]+=e[i].l;
	}
	fo(t,0,(1<<n)-1)fo(x,1,n)f[t][x]=-1;
	fo(t,1,(1<<(n-1))-1)
	if (t&1)f[t][1]=val[t];
	fo(t,1,(1<<n)-1)
		fo(x,1,n)
		if (f[t][x]>-1){
			int u=((1<<n)-1)^t;
			int p=u;
			for(;u;u=(u-1)&p){
				fo(y,1,n)
				if (((1<<(y-1))&u)>0&&d[x][y])f[t^u][y]=max(f[t^u][y],f[t][x]+d[x][y]+val[u]);
			}
		}
	printf("%d\n",sum-f[(1<<n)-1][n]);
	return 0;
}