#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int&i:a)cin>>i;
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	ll ans=0;
	for(int i=0;i<k;i++)ans+=a[i];
	cout<<ans;
	
}