#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll N;
	cin >> N;
	vector<ll> A(N);
	rep(i, N) cin >> A[i];

	map<ll, ll> M;
	rep(i, N) {
		map<ll, ll>::iterator it = M.lower_bound(A[i]);
		if(M.size() == 0 || it == M.begin()) {
			M[A[i]]++;
		} else {
			it--;
			(*it).second--;
			if((*it).second == 0) {
				M.erase(it);
			}
			M[A[i]]++;
		}
	}

	ll ans = 0;
	for(pair<ll, ll> item: M) {
		ans += item.second;
	}
	cout << ans  << endl;
	

}
