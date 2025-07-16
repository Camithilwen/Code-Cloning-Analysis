#include<bits/stdc++.h>
using namespace std;
int counter[200005];
bool balls[200005];
bool picked[200005];
void solve(int k){
	for(int i=1; i*i<=k; i++){
		if(k%i==0){
			counter[i]++;
			if(i!=k/i) counter[k/i]++;
		}
	}
}
int main(){
	int n;
	cin>>n;
	int ret = 0;
	for(int i=1; i<=n; i++) cin>>balls[i];
	for(int i=n; i>=1; i--){
		if(balls[i] && counter[i]%2) continue;
		if(!balls[i] && counter[i]%2==0) continue;
		picked[i] = true;
		ret++;
		solve(i);
	}
	cout<<ret<<'\n';
	for(int i=1; i<=n; i++){
		if(picked[i]) cout<<i<<" ";
	}
}