#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b

signed main(){
	int n; cin>>n;
	string a,b,c; cin>>a>>b>>c;
	int ans=0;
	rep(i,0,n){
		if(a[i]!=b[i] && b[i]!=c[i] && a[i]!=c[i])ans+=2;
		else if(a[i]==b[i] && b[i]==c[i] && a[i]==c[i])ans=ans;
		else ans++;
	}
	cout<<ans<<endl;
	return 0;
}