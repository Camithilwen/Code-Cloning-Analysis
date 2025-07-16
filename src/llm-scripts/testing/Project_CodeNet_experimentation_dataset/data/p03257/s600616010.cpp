#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

cat gcd(cat x, cat y) {
	if(x > y) swap(x, y);
	return (x == 0) ? y : gcd(y%x, x);
}

cat lcm(cat x, cat y) {
	return x / gcd(x, y) * y;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector<cat> > A(N, vector<cat>(N, 1));
	vector<int> P;
	for(int p = 4; ; p++) {
		bool is_prime = true;
		for(int i = 2; i*i <= p; i++) is_prime &= (p%i != 0);
		if(!is_prime) continue;
		P.push_back(p);
		if((int)P.size() == N+10) break;
	}
	for(int i = 0; i < N; i += 2) for(int j = 0; j < N; j += 2) A[i][j] = P[i/2] * P[N/2+1+j/2];
	for(int i = 1; i < N; i += 2) for(int j = 1; j < N; j += 2) A[i][j] = 3 * A[i-1][j-1];
	for(int i = 0; i < N; i++) for(int j = 1-(i&1); j < N; j += 2) {
		if(i > 0) A[i][j] = lcm(A[i][j], A[i-1][j]);
		if(j > 0) A[i][j] = lcm(A[i][j], A[i][j-1]);
		if(i+1 < N) A[i][j] = lcm(A[i][j], A[i+1][j]);
		if(j+1 < N) A[i][j] = lcm(A[i][j], A[i][j+1]);
		if(j&1) A[i][j] *= 2;
		A[i][j]++;
	}
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cout << A[i][j] << ((j == N-1) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing
