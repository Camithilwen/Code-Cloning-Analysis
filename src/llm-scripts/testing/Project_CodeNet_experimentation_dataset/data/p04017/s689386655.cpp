#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100010
using namespace std;
int n,l,q;
int a[maxn],tp[maxn][25];
void init(){
	int to=1;
	for(int t=1;t<=n;++t){
		while(to<n&&a[t]+l>=a[to+1])to++;
		tp[t][0]=to;
	}
	for(int t=n;t>=1;--t){
		for(int i=1;i<=20;++i){
			tp[t][i]=tp[tp[t][i-1]][i-1];
		}
	}
}
bool check(int a,int b,int k){
	int now=0;
	for(int t=20;t>=0;--t){
		if(now+(1<<t)<=k){
			now+=1<<t;
			a=tp[a][t];
		}
	}
	return a>=b;
}
int getans(int a,int b){
	int l=1,r=n,ans=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(a,b,mid)){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int t=1;t<=n;++t)scanf("%d",&a[t]);
	scanf("%d%d",&l,&q);
	init();
	for(int t=1;t<=q;++t){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b)swap(a,b);
		printf("%d\n",getans(a,b));
	}
}