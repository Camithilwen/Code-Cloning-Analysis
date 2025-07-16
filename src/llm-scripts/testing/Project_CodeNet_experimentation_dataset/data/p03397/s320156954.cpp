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
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

void add(map<string, int> &M, string s) {
	for(int i = 0; i <= (int)s.length(); i++) M[s.substr(0, i)] = 0;
}

void add_edges(map<string, int> &M, vector< vector<int> > &G, string end) {
	ALL_THE(M, it) if(it->ff != end && G[it->ss].empty())
		for(int k = 0; k < 2; k++) G[it->ss].push_back(M[it->ff+(char)('0'+k)]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	string S;
	cin >> S;
	int N = S.length();
	map<string, int> M;
	add(M, "01");
	add(M, "000");
	add(M, "0011");
	add(M, "0010");
	add(M, "101");
	add(M, "1000");
	add(M, "1001");
	add(M, "111");
	add(M, "11000");
	add(M, "11001");
	add(M, "1101");
	int m = 0;
	ALL_THE(M, it) it->ss = m++;
	vector< vector<int> > G(m);
	G[M["01"]].push_back(M[""]);
	G[M["000"]].push_back(M["0"]);
	G[M["0011"]].push_back(M[""]);
	G[M["0010"]].push_back(M["00"]);
	G[M["101"]].push_back(M["1"]);
	G[M["1000"]].push_back(M["10"]);
	G[M["1001"]].push_back(M["10"]);
	G[M["11000"]].push_back(M["110"]);
	G[M["11001"]].push_back(M["110"]);
	G[M["1101"]].push_back(M["11"]);
	add_edges(M, G, "111");
	vector<string> V(m);
	ALL_THE(M, it) V[it->ss] = it->ff;

	cat mod = 1000000007;
	vector< vector<cat> > ans(N+1, vector<cat>(m, 0));
	ans[0][0] = 1;
	for(int i = 0; i < N; i++) for(int j = 0; j < m; j++) if(G[j].size() == 2)
		for(int k = 0; k < 2; k++) if(S[i] == '?' || S[i] == '0'+k) {
			string s = V[j] + (char)('0'+k);
			int id = M[s];
			while(G[id].size() == 1) id = G[id][0];
			ans[i+1][id] += ans[i][j];
			if(ans[i+1][id] >= mod) ans[i+1][id] -= mod;
		}
	cat ansF = 0, pw2 = 1;
	for(int i = N-1; i >= 0; i--) {
		if(S[i] == '?') pw2 = (pw2 * 2) % mod;
		ansF += ans[i][M["111"]] * pw2 % mod;
	}
	for(int i = 0; i < m; i++) if(G[i].size() != 1) {
		string s = V[i];
		int sum = 0;
		for(int j = 0; j < (int)s.length(); j++) sum += (s[j] == '1') ? 1 : -1;
		if(sum > 0) ansF += ans[N][i];
	}
	ansF %= mod;
	if(ansF < 0) ansF += mod;
	cout << ansF << "\n";

	// 01 -> .
	// 000 -> 0
	// 0011 -> .
	// 0010 -> 00
	// 101 -> 1
	// 1000 -> 10
	// 1001 -> 10
	// 111 -> WIN
	// 11000 -> 110
	// 11001 -> 110
	// 1101 -> 11
	return 0;}

// look at my code
// my code is amazing
