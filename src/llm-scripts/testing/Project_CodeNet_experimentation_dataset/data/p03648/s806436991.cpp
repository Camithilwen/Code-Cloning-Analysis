#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll a[50];
int main() {
	for(ll i=0;i<50;i++){
		a[i]=49-i;
	}
	ll k;
	cin>>k;
	for(ll i=0;i<50;i++){
		a[i]+=k/50;
	}
	for(ll i=0;i<k%50;i++){
		a[i]++;
	}
	cout << 50<<endl;
	for(ll i=0;i<50;i++){
		cout << a[i]<<" ";
	}
	// your code goes here
	return 0;
}