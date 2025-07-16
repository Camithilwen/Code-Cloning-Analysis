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



int n, a[111],b[111],c[111],d[111];
P p[111], pp[111];
bool used[111];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		p[i] = {b[i],a[i]};
	}
	for(int i = 0; i < n; i++){
		cin >> c[i] >> d[i];
		pp[i] = {c[i],d[i]};
	}
	sort(p,p+n,greater<P>());
	sort(pp,pp+n);
	
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(pp[i].second < p[j].first) continue;
			if(pp[i].first < p[j].second) continue;
			if(used[j]) continue;
			used[j] = 1;
			cnt++;
			break;
		}
	}
	cout << cnt << endl;
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