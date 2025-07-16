#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int n;
	string s;
	cin >> n >> s;
	
	vector<int> w(n+1), e(n+1);
	w[0] = 0;
	e[0] = 0;
	REP(i,n){
		w[i+1] = w[i];
		e[i+1] = e[i];
		if(s[i]=='W') w[i+1]++;
		if(s[n-1-i]=='E') e[i+1]++;
	}
	
	int ans=1000000;
	REP(i,n){
		chmin(ans, w[i+1]+e[n-i]-1);
	}
	
	cout << ans << endl;
	
	
	
	return 0;
}