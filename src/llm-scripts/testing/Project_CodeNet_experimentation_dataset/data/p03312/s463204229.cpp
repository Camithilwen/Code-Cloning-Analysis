#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
	int N;
	cin >> N;
	vector<ll> A(N),S(N+1);
	for(int i=0;i<N;i++){
		cin >> A[i];
		S[i+1] = S[i]+A[i];
	}
	ll ans = 1e18;
	auto sum = [&](int l,int r){
		return S[r]-S[l];
	};
	int l = 1,r = 3;
	for(int i=1;i<N;i++){
		while(true){
			ll s1 = abs(sum(l,0)-sum(i,l));
			ll s2 = abs(sum(l+1,0)-sum(i,l+1));
			if(s1>s2) l++;
			else break;
		}
		while(true){
			ll s1 = abs(sum(N,r)-sum(r,i));
			ll s2 = abs(sum(N,r+1)-sum(r+1,i));
			if(s1>s2) r++;
			else break;
		}
		ll ma = max({sum(l,0),sum(i,l),sum(r,i),sum(N,r)});
		ll mi = min({sum(l,0),sum(i,l),sum(r,i),sum(N,r)});
		ans = min(ans,ma-mi);
	}
	cout << ans << endl;
}