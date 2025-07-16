#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;

int main(){
	ll K;
	cin>>K;
	cout<<50<<endl;
	REP(i,50){
		ll ans;
		if (i<K%50){
			ans=100-(K%50)+K/50;
		}else{
			ans=49-(K%50)+K/50;
		}
		if (i){
			cout<<" ";
		}
		cout<<ans;
	}
	cout<<endl;
	return 0;
}