#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)
#define PI 3.14159265358979

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n, a[101010];
void solve(){
	cin >> n;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		cnt += abs(a[i]-a[i-1]);
	}
	cnt += abs(a[n]);
	
	for(int i = 1; i <= n; i++){
		cout << cnt-(abs(a[i]-a[i-1])+abs(a[i]-a[i+1]))+abs(a[i-1]-a[i+1]) << endl;
	}
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}