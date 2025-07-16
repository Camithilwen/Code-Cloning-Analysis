#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
#define all(x) (x).begin(),(x).end()

int main(){
	ll n; cin>>n;
	vector<ll> v(5);
	rep(i,5) cin>>v[i];
	sort(all(v));
	cout<<(n+v[0]-1)/v[0]+4<<endl;
}