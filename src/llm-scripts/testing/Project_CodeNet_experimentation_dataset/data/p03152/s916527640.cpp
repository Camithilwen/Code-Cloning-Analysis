#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=1010;

ll n, m, k, u, v, x, y, t, a, b, ans=1;
int A[MAXN], B[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<n; i++) cin>>A[i];
	for (int i=0; i<m; i++) cin>>B[i];
	sort(A, A+n);
	sort(B, B+m);
	reverse(A, A+n);
	reverse(B, B+m);
	int i=0, j=0, t=0;
	for (int num=n*m; num; num--, t++){
		if (A[i]!=num && B[j]!=num) ans=ans*(i*j-t)%mod;
		if (A[i]!=num && B[j]==num) ans=ans*i%mod;
		if (A[i]==num && B[j]!=num) ans=ans*j%mod;
		
		i+=(A[i]==num);
		j+=(B[j]==num);
	}
	cout<<ans<<"\n";
	
	return 0;
}
