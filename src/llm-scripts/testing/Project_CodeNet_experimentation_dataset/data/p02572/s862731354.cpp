#include<bits/stdc++.h>
using namespace std;
long long M=1e9+7;
void solve(){
	int n;
	cin>>n;
	long long sum=0,ans=0,p;
	for(int i=0;i<n;i++){
		cin>>p;
		ans= (ans+(p*sum)%M)%M;
		sum=(sum+p)%M;
	}
	cout<<ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();

}