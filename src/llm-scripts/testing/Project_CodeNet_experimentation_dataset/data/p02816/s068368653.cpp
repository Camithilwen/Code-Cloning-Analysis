#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=998244353;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

vi Z_Algorithm(string s){
	int S=s.size();
	vi A(S);
	A[0]=S;
	int i=1,j=0;
	while(i<S){
		while(i+j<S&&s[j]==s[i+j]) j++;
		A[i]=j;
		if(!j){
			i++;continue;
		}
		int k=1;
		while(i+k<S&&k+A[k]<j) A[i+k]=A[k],k++;
		i+=k;j-=k;
	}
	return A;
}

int n;
vi a,b;

int main(){
	cin>>n;
	a=b=vi(n);
	for(auto &i:a) cin>>i;
	for(auto &i:b) cin>>i;
	vi used(n,1);
	for(int j=0;j<30;j++){
		vi c(n);
		for(int k=0;k<2;k++){
			string s;
			for(int i=0;i<n;i++){
				if(((b[i]&1<<j)>0)^(k==1)) s+='1';
				else s+='0';
			}
			for(int i=0;i<n;i++){
				if(a[i]&1<<j) s+='1';
				else s+='0';
			}
			for(int i=0;i<n;i++){
				if(a[i]&1<<j) s+='1';
				else s+='0';
			}
			vi z=Z_Algorithm(s);
			for(int i=0;i<n;i++) if(z[i+n]>=n) c[i]=1;
//			cout<<s<<endl;
//			for(auto i:z) cout<<i<<' ';cout<<endl;
		}
//		for(auto i:c) cout<<i<<' ';
//		cout<<endl;
		for(int i=0;i<n;i++) used[i]&=c[i];
	}
	for(int i=0;i<n;i++) if(used[i]) cout<<i<<' '<<(a[i]^b[0])<<endl;
}