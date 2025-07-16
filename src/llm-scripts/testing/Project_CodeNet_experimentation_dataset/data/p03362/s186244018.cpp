#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define rrep(i,j,n) for(ll i = (ll)(j); i < (ll)(n); i++)
#define mrep(i,n) for (ll i = (ll)(n-1); i > 0; i--)
#define be(v) (v).begin(), (v).end()
#define scout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

bool isplime(int p){
	if(p==1) return false;
	for(int i=2;i<p;i++) {
		if(p%i==0) return false;
	}
	return true;
}

int main() {
	int n; cin >> n;
	for(int i=31;i<=55555;i+=30) {
		if(isplime(i)) {
			if(i!=31) cout << " ";
			cout << i;
			n--;
		}
		if(n==0) break;
	}
	cout << endl;
}