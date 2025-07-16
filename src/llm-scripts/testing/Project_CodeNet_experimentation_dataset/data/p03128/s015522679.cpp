#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

vector<string> dp(10001," ");
vector<pair<int,char>> a(10);



string string_max(int i,int j){
	string s = dp[i];
	string t = dp[i + a[j].fs];
	char c = a[j].sc;
	if(s == "0"){
		s = c;
	}	
	else{
		auto index = lower_bound(RALL(s),c);
		s.insert(index.base(),c);
	}
	string ans;
	// cout << "s" << s << " t " << t << endl;
	// cout << (s > t) << endl;
	if (t == " "){
		ans =  s;
	}
	else{
		if(s.size() > t.size()){
			ans = s;
		}
		else if(s > t){
			ans =  s;
		}
		else{
			ans =  t;
		}
	}
	return ans; 
}


int main(){
	int n,m;cin>>n>>m;
	a.resize(m);
	int match[9] = {2,5,5,4,5,6,3,7,6};
	for(int i = 0; i < m; i++) {
		char x;cin>>x;
		a[i] = mp(match[x - '0' - 1],x);
	}
	sort(ALL(a));
	// for(int i = 0; i < m; i++) {
	// 	cout << a[i].fs << endl;
	// }


	dp[0] = "0";
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(dp[i] != " " && i + a[j].fs <= n){
				dp[i + a[j].fs] = string_max(i,j);
				// cout << "i " << i << " j " << j << endl;

			}
			// for(int i = 0; i <= n; i++) {
			// 	cout << dp[i] << " ";
			// }
			// cout << endl;
		}
	}
	// for(int i = 0; i <= n; i++) {
	// 	cout << dp[n] << endl;
	// }
	cout << dp[n] << endl;
	return 0;
}