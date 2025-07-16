#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
using namespace std; using ll = long long; using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
//**デバッグ準備**//
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail>
void debug_out(Head h, Tail... t) {
	cerr << " " << h;
	if (sizeof...(t) > 0) cerr << " :";
	debug_out(t...);
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> vec) {
	for (size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	return os;
}
ll ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{
	return firstElof.first > secondElof.first;
}
//**Snippetリスト**//
//rep, vin, all, iteLoop//
//gcdlcm, isPrime, eratos, Npow, divisor, modinv, bitSearch, bitList, dfs, bfs//
//dijkstra, WarshallFloyd, BellmanFord, UnionFind, COM, digitDP ,RMQ//
ll i, j, k, l; ll N, M, K, H, W, L, X, Y, Z;
ll MOD = 1000000007; ll INF = 1LL << 60; ll ans = 0; ll z = 0, o = 1;
vl flag, color, D; vll path;
//***********//
int main() {
	cin >> H >> W;
	vll A(H, vl(W, 0));
	vll B(H, vl(W, 0));
	vll D(H+1, vl(W+1, 0));
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			cin >> A[i][j];
		}
	}
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			cin >> B[i][j];
			D[i+1][j+1] = abs(A[i][j] - B[i][j]);
		}
	}
	ll M = (H + W) * 80;
	vector<vll> dp(H+1, vll(W+1, vl(M, 0)));
	dp[1][1][D[1][1]] = 1;
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= W; j++) {
			for (k = 0; k < M; k++) {
				if (i == H && j == W) continue;
				if (i != H) {
					if (k + D[i + 1][j] < M) dp[i + 1][j][k + D[i + 1][j]] |= dp[i][j][k];
					if (abs(k - D[i + 1][j]) < M) dp[i + 1][j][abs(k - D[i + 1][j])] |= dp[i][j][k];
				}
				if (j != W) {
					if (k + D[i][j + 1] < M) dp[i][j + 1][k + D[i][j + 1]] |= dp[i][j][k];
					if (abs(k - D[i][j + 1]) < M) dp[i][j + 1][abs(k - D[i][j + 1])] |= dp[i][j][k];
				}
			}
		}
	}
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= W; j++) {
			for (k = 0; k < M; k++) {
				//if(dp[i][j][k]) debug(i, j, k, dp[i][j][k]);
			}
		}
	}
	for (k = 0; k < M; k++) {
		if (dp[H][W][k]) { 
			cout << k; 
			exit(0);
		}
	}
}