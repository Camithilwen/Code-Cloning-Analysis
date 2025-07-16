#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
#define LLINF 100000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int H,W;
string s[2010];
int dp[2010][2010];
int L[2010],R[2010];
int max_rect(vector<int> v){
	stack<int> st;
	for(int i=0;i<v.size();i++){
		while(!st.empty()&&v[st.top()]>=v[i])st.pop();
		if(st.empty())L[i]=-1;
		else L[i]=st.top();
		st.push(i);
	}
	while(!st.empty())st.pop();
	for(int i=v.size()-1;i>=0;i--){
		while(!st.empty()&&v[st.top()]>=v[i])st.pop();
		if(st.empty())R[i]=v.size();
		else R[i]=st.top();
		st.push(i);
	}
	int res = 0;
	for(int i=0;i<v.size();i++){
		if(L[i]==-1)res = max(res,(R[i]-L[i]-1)*v[i]);
		else res = max(res,(R[i]-L[i])*v[i]);
	}
	return res;
}
int main(){
	cin >> H >> W;
	for(int i=0;i<H;i++)cin >> s[i];
	for(int i=0;i<W;i++)dp[0][i]=W-i;
	for(int i=1;i<H;i++){
		dp[i][W-1]=1;
		for(int j=W-2;j>=0;j--){
			if(s[i][j]==s[i-1][j]&&s[i][j+1]==s[i-1][j+1])dp[i][j]=dp[i][j+1]+1;
			else if(s[i][j]!=s[i-1][j]&&s[i][j+1]!=s[i-1][j+1])dp[i][j]=dp[i][j+1]+1;
			else dp[i][j]=1;
		}
	}
	/*for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}*/
	int ans = 0;
	for(int j=0;j<W;j++){
		vector<int> v;
		for(int i=0;i<H;i++){
			v.pb(dp[i][j]);
		}
		ans = max(ans,max_rect(v));
	}
	cout << ans << endl;
	return 0;
}