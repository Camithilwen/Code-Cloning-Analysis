#include <bits/stdc++.h>
using namespace std;
int n;
int a[600005],b[200005],c[600005];
int l,r=1,o;
int main(){
	cin>>n;
	for(int i=0;i<=n*2;++i){
		if(i-n){
			cin>>a[i+(i<n?n+1:-n-1)];
		}
	}
	a[n*2+1]=a[n+1];
	a[n]=a[0]; 
	for(int i=0;i<n;++i){
		b[i]=a[0]^a[n+1+i];
	}
	for(int i=0;i<=n*2;++i){
		a[i]^=a[i+1];
	}
	for(int i=0;i<n;++i){
		a[i+n*2+1]=a[i+n+1];
	}
	a[n]=1<<30;
	for(int i=0;i<=n*2;++i){
		if((o=c[i-l]+i>=r)){
			for(l=i,r=max(r,i);a[r-l]==a[r];++r);
		}
		if((c[i]=o?r-l:c[i-l])==n){
			cout<<i-n-1<<' '<<b[i-n-1]<<'\n';
		}
	}
	return 0;
} 