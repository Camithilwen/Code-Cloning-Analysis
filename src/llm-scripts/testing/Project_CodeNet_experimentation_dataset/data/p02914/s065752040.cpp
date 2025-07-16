#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}





///////////////////////////

ll p(ll n) {
	if (n == 0) { return 1; }
	return 2 * p(n - 1);
}


int main() {

	ll N;
	cin >> N;

	vector<ll> A(N + 1);

	repn(i, N) cin >> A[i];

	sort(++A.begin(), A.end(), greater<ll>());

	vector<vector<ll>> d(N + 1,vector<ll>(60));

	vector<ll> count1(60);

	repn(i, N) {
		ll t = A[i];
		rep(j,60){
			d[i][59-j] = t%2;
			count1[59-j]+= d[i][59-j];
			t /= 2;
		}
	}
	
	repn(i, N) {
		rep(j, 60) {
			if (count1[j] % 2 == 1) { d[i][j] = 0; }
		}
	}

	/*
	repn(i, N) {
		rep(j, 60) {
			cout << d[i][j];
		}
		cout << endl;
	}
	*/


	repn(i, N) {
		ll K=-1;
		rep(j,60){
			if (d[i][j] == 1) { K = j; break; }
		}

		//cout << i << K << endl;

		if (K == -1) { continue; }

		repn(l, N) {
			if (l == i) { continue; }

			if (d[l][K] == 1) {
				for (int j = K; j < 60; j++) {
					d[l][j] = (d[i][j] + d[l][j]) % 2;
				}
			}
		}

		/*
		repn(i, N) {
			rep(j, 60) {
				cout << d[i][j];
			}
			cout << endl;
		}
		*/
		
	}

	vector<ll> sum(60, 0);

	repn(i, N) {
		rep(j, 60) {
			sum[j]+=d[i][j];
		}
	}

	//rep(j, 60) { cout << count1[j] << endl; }

	ll ans=0;

	rep(j, 60) {
		ans += (count1[j]%2+2*(sum[j]%2)) * p(59-j);
	}

	cout << ans;

	

	system("PAUSE");

}
