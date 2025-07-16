#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2000006;
const ll MOD = 1000000007;

ll a[N];
int bts[66];
int stb[66];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	ll ans = 0;
	
	for(int i=n;i>0;i--){
		for(int j=0;j<61;j++){
			ll t = (1ll<<j);
			t %= MOD;
			if((a[i])&(1ll<<j)){
				ll b = stb[j];
				bts[j]++;
				ans += t*b;
				ans %= MOD;
			}else{
				ll b = bts[j];
				stb[j]++;
				ans += t*b;
				ans %= MOD;
			}
		}
	}
	
	cout<<ans;
	
	return 0;
}
