#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,ans=0x3f3f3f3f;
int a[100000+5];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		int j=m+i-1;
		ans=min(ans,min(abs(a[i])+abs(a[j]-a[i]),abs(a[j])+abs(a[j]-a[i])));
	}
	if(ans==0x3f3f3f3f) cout<<0<<endl;
	cout<<ans<<endl;
}