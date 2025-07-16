#include<bits/stdc++.h>
using namespace std;
long long a[1100],na,n;
bool p(int x){for (int i=2;i<x;i++)if (x%i==0)return 0;return 1;}
int main(){
	for (int i=2;i<=8000;i++)if (p(i))a[++na]=i;
	cin>>n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			if ((i+j)%2==0)cout<<a[(i+j)/2]*a[(i-j+n)/2+n+1]<<' ';
			else cout<<a[(i+j)/2]*a[(i-j+n+1)/2+n+1]*a[(i+j+1)/2]*a[(i-j+n-1)/2+n+1]+1<<' ';
		cout<<endl;
	}
	return 0;
}