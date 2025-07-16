#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	map<ll,ll>ch;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		ch[x]++;
		if(ch[x]==2){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	// your code goes here
	return 0;
}