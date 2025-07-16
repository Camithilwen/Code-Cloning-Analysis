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
typedef vector<int> vecI;

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

	string S;
	cin >> S;

	const int na = 753;
	j = S[0] - '0';
	j *= 10;
	j += S[1] - '0';
	j *= 10;
	j += S[2] - '0';
	
	int ans = abs(j - na);
	rep(i, 3, S.size()) {
		j %= 100;
		j *= 10;
		j += S[i] - '0';
		ans = min(ans, abs(j - na));
	}
	cout << ans << endl;
	return 0;
}
