#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

string s;
bool done[334][334][334];
int memo[334][334][334];

int solve(int i, int j, int k){
	int l;
	if(done[i][j][k]){
		return memo[i][j][k];
	}
	done[i][j][k] = true;
	if(i==j){
		return memo[i][j][k] = 1;
	}else if(i>j){
		return memo[i][j][k] = 0;
	}
	memo[i][j][k] = max(solve(i+1,j,k),solve(i,j-1,k));
	if(s[i]==s[j]){
		memo[i][j][k] = max(memo[i][j][k],solve(i+1,j-1,k)+2);
	}else if(k){
		memo[i][j][k] = max(memo[i][j][k],solve(i+1,j-1,k-1)+2);
	}
	return memo[i][j][k];
}

int main(void){
	int k;
	cin >> s >> k;
	cout << solve(0,s.l_ength()-1,k) << endl;
	return 0;
}
