#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,k,x[maxn];
const int inf=0x3f3f3f3f;
long long a,b,now;
int topp,topn;
long long ans;
int main(){
	cin>>n>>k;
	ans=inf;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=1;i+k-1<=n;i++){
		a=min(abs(x[i]),abs(x[i+k-1]));
		b=x[i+k-1]-x[i];
		ans=min(ans,a+b);
	}
	cout<<ans;
}