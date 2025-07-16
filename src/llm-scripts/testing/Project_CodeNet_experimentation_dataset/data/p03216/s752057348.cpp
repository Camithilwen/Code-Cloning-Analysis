#include<bits/stdc++.h>
#define ll long long
#define maxn 1000100
#define mod 1000000007
using namespace std;
char a[maxn];
int n,q,k;
ll ans=0;
void sol(){
	ans=0;
	ll d=0,dm=0,m=0;
	for(int i=0;i<n;i++){
		if(i>=k){
			if(a[i-k]=='D'){
				dm-=m;
				d--;
			}
			if(a[i-k]=='M') m--;
		}
		if(a[i]=='C') ans+=dm;
		if(a[i]=='D') d++;
		if(a[i]=='M') dm+=d,m++;
	}
}
int main(){
	scanf("%d",&n);
	scanf("%s",a);
	scanf("%d",&q);
	while(q--){
		scanf("%d",&k);
		sol();
		printf("%lld\n",ans);
	}
	return 0;
}