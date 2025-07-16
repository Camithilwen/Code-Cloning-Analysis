#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e10;
const long double PI = (acos(-1));


signed main() {
	int N;
	cin >> N;
	vector<int>A(N), B(N);
	rep(i, N)cin >> A[i] >> B[i];
	priority_queue<P>q;
	rep(i, N) {
		P p = { A[i] + B[i] ,i };
		q.push(p);
	}
	int ans = 0;
	rep(i, N) {
		P p = q.top();
		q.pop();
		if (i % 2 == 0)ans += A[p.second];
		else ans -= B[p.second];
	}
	cout << ans << endl;
}