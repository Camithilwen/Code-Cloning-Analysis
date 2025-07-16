#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
 	bool ac[100010]={};
	ll wa[100010]={};
int main() {
	ll n,k;
	cin>>n>>k;

	for(ll i=0;i<k;i++){
		ll x;string s;
		cin>>x>>s;x--;
		if(s=="AC"){
			ac[x]=true;
		}
		else{
			if(ac[x]!=true){
				wa[x]++;
			}
		}
	}
		ll cnt1=0;
		ll cnt2=0;
		for(ll i=0;i<n;i++){
			if(ac[i]){
				cnt1++;
				cnt2+=wa[i];
			}
		}
		cout << cnt1<<" "<<cnt2;	
	// your code goes here
	return 0;
}