// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) {return (x < 0) ? -x : x;}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string S;
	int K;
	cin >> S >> K;
	S += '0';
	int L = S.length(), n1 = 0, N = 0;
	vector<int> A;
	for(int i = 0, cur = 0; i < L; i++) {
		if(S[i] == '0') {
			A.push_back(cur);
			N++;
			cur = 0;
		}
		else n1++, cur++;
	}
	K = min(K, n1);
	reverse(begin(A), end(A));
	cat mod = 998244353;
	vector< vector< vector<cat> > > cnt(N+1, vector< vector<cat> >(K+1, vector<cat>(K+1, 0)));
	cnt[0][0][0] = 1;
	for(int i = 0; i < N; i++) {
		// increase/keep A[i]
		for(int k = 0; k <= K; k++) {
			cnt[i+1][k][k] = cnt[i][k][k];
			for(int j = k-1; j >= 0; j--) cnt[i+1][j][k] = cnt[i+1][j+1][k] + cnt[i][j][k];
		}
		// decrease A[i]
		for(int j = 0; j <= K; j++)
			for(int l = 1; l <= A[i]; l++)
				for(int k = j; k <= K-l; k++) cnt[i+1][j+l][k+l] += cnt[i][j][k];
		for(int j = 0; j <= K; j++) for(int k = j; k <= K; k++) cnt[i+1][j][k] %= mod;
	}
	cat ans = 0;
	for(int i = 0; i <= K; i++) ans += cnt[N][0][i];
	ans %= mod;
	cout << ans << "\n";
}
