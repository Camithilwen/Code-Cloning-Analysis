#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[200005],b[200005]; 
int main(){
	cin>>n>>k;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	if(k>50){
		for(int i=0;i<n;++i){
			cout<<n<<' ';
		}
		cout<<'\n';
		return 0;
	}
	for(int i=0;i<k;++i){
		memset(b,0,sizeof(b));
		for(int i=0;i<n;++i){
			int l=max(0,i-a[i]);
			int r=min(n-1,i+a[i]);
			b[l]++;
			if(r+1<n){
				b[r+1]--;
			} 
		}
		for(int i=1;i<n;++i){
			b[i]+=b[i-1];
		}
		for(int i=0;i<n;++i){
			a[i]=b[i];
		}
	}
	for(int i=0;i<n;++i){
		cout<<a[i]<<' ';
	}
	cout<<'\n';
	return 0;
} 