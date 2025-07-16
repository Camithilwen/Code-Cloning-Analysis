#include <iostream>
using namespace std; 
long long p[100001],x[100001],ans=0;
int n,s,l,r;
int main(){
	cin>>n>>s;
	for (int i=1;i<=n;i++)
		cin>>x[i]>>p[i];
	l=1;r=n;
	while (l<=r){
	if (s<=x[l]){
		cout<<x[r]-s+ans;
		return 0;
	} 
	else if (s>=x[r]){
		cout<<ans+s-x[l];
		return 0;
	}  //所有住处都在s的一侧，可以直接开过去 		
	if (p[l]>=p[r]){
		ans+=x[r]-x[l];
		while (l<r&&p[l]>=p[r]) p[l]+=p[r--];
	}
	else{
		ans+=x[r]-x[l];
		while (l<r&&p[l]<p[r]) p[r]+=p[l++];
	}
	}
	return 0;
} 