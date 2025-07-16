#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n;
long long ans,a,b,x[100009]; 
int main(){
	scanf("%d%lld%lld",&n,&a,&b);
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
	for(int i=2;i<=n;i++)ans+=min(a*(x[i]-x[i-1]),b);
	printf("%lld\n",ans);
	return 0;
}
