#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n,l,ans=1e9; cin>>n>>l;
	int S[n], sum=0;
	for(int i=0; i<n; i++){
		S[i] = l+i+1-1;
		sum+=S[i];
	}
	for(int i=0; i<n; i++){
		int x = abs(sum - (sum-S[i]));
		ans = min(ans, x);
	}
	if(sum>=0)cout<<sum-ans<<endl;
	else cout<<sum+ans<<endl;
}
