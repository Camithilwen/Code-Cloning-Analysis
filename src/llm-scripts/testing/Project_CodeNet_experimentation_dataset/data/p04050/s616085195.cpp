#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#include<stack>
#include<algorithm>
#define rg register
#define ll long long
#define LDB long double
#define ull unsigned long long
#define view(i,x) for(rg int i=hd[x];i!=-1;i=e[i].nt)
#define go(i,x,a) for(rg int i=a;i<x;i++)
#define inf 0x3f3f3f3f
#define INF 0x7fffffff
using namespace std;

const int maxn=105;
int n,a[maxn],m,b[maxn];

inline int rd(){
	int ret=0,af=1; char gc=getchar();
	while(gc < '0' || gc > '9'){ if(gc=='-') af=-af; gc=getchar(); }
	while(gc >= '0' && gc <= '9') ret=ret*10+gc-'0',gc=getchar();
	return ret*af;
}

inline bool cmp(int a,int b){
	return a%2 > b%2;
}

int main(){
	n=rd(); m=rd();
	go(i,m+1,1) a[i]=rd();
	sort(a+1,a+m+1,cmp);
	int t=0;
	while(a[t+1]%2 == 1) t++;
	if(t > 2){ printf("Impossible"); return 0; }
	if(t == 2) swap(a[m],a[2]);
	go(i,m+1,1) printf("%d ",a[i]); puts("");
	go(i,m+1,1) b[i]=a[i]; 
	if(m == 1) m++;
	b[1]--; b[m]++;
	if(b[1] == 0){
		printf("%d\n",m-1);
		go(i,m+1,2) printf("%d ",b[i]);
	}else{
		printf("%d\n",m);
		go(i,m+1,1) printf("%d ",b[i]);
	}
	return 0;
}//Faze
