#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <complex>
#include <functional>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define all(v) v.begin(),v.end()
#define trav(x, v) for(auto &x : v)
#define sz(v) int((v).size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

void fail(){
	puts("No");
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<vi> a(3, vi(n));
	trav(v, a) trav(x, v) cin >> x;
	vi perm(n);
	bool sign[2] = {};
	rep(i,0,n){
		int ix = (a[0][i]-1)/3;
		if(a[1][i] != 3*ix+2) fail();
		if(min(a[0][i], a[2][i]) != 3*ix+1
			|| max(a[0][i],a[2][i]) != 3*ix+3) fail();
		sign[i&1] ^= a[0][i] > a[2][i];
		perm[i] = ix;
		if((i+ix)&1) fail();
	}
	int numofcycles[2] = {};
	vector<bool> vis(n);
	rep(i,0,n) if(!vis[i]){
		++numofcycles[i&1];
		int j = i;
		do {
			vis[j] = 1;
			j = perm[j];
		} while(j != i);
	}
	int nn[2] = {n/2+(n&1), n/2};
	if(sign[0] != (nn[1]+numofcycles[1])%2
		|| sign[1] != (nn[0]+numofcycles[0])%2)
		fail();
	puts("Yes");
}