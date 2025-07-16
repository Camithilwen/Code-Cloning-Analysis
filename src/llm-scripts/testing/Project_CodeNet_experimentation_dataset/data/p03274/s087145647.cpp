#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>
#include <queue>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <map>
#include <functional>
#include <limits>
#include <set>
#include <stack>
#include <cctype>
#define rep(i,a,b) for((i)=a;i<(int)(b);i++)

#define AAA (1000000007) 


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pairII;


ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll powD(ll a, ll b) {
	ll ans = 1;
	a %= AAA;
	for (int i = 0; i < b; i++)
	{
		ans *= a;
		ans %= AAA;
	}
	return ans;
}


int main() {
	int i, j, k;

	int N, M, K;


	vector<int> X;
	cin >> N >> K;
	rep(i, 0, N) {
		int x;
		cin >> x;
		X.push_back(x);
	}
	ll ans = abs(X[0])*2 + abs(X[N - 1])*2;

	rep(i, 0, N-K+1) {
		ll a = min(abs(X[i]), abs(X[i + K-1]));
		ll b = max(abs(X[i]), abs(X[i + K-1]));
		if (X[i] < 0 && X[i + K - 1]>0) {
			ans = min(ans, a * 2 + b);
		}
		else {
			ans = min(ans,b);
		}

	}
	cout << ans;
	return 0;
}