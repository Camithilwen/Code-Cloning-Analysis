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

	set<ll> S;
	map<ll, ll> M;
	rep(i, N) {
		set<ll>::iterator it = S.lower_bound(A[i]);
		if(S.size() == 0 || it == S.begin()) {
			S.insert(A[i]);
			M[A[i]]++;
		} else {
			it--;
			M[*it]--;
			if(M[*it] == 0) {
				M.erase(*it);
				S.erase(*it);
			}
			S.insert(A[i]);
			M[A[i]]++;
		}
	}

	ll ans = 0;
	for(pair<ll, ll> item: M) {
		ans += item.second;
	}
	cout << ans  << endl;
	

}