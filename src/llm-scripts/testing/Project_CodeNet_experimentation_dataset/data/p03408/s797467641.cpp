#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
	ios::sync_with_stdio(false);

	int N,M; cin>>N;
	vector<string> s(N);
	rep(i,N) cin>>s[i];
	cin>>M;
	vector<string> t(M);
	rep(i,M) cin>>t[i];

	int ans=0;
	rep(i,N){
		string taka = s[i];
		int money = 0;
		rep(j,N){
			if(taka == s[j]) money++;
		}
		rep(k,M){
			if(taka == t[k]) money--;
		}
		ans = max(ans,money);
	}
	cout << ans << endl;
}
