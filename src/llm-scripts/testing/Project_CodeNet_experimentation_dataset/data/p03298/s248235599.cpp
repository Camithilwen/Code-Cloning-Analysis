//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
LL res;
int dp[20][20];
// dp[i][j] 前i个组成长度为j的B的前缀 
string r_s="";
int check(string A,string B){
//	cout<<A<<" "<<B<<" "<<r_s<<endl;
	
	A='$'+A;
	B='^'+B;
	rb(i,0,19)
		rb(j,0,19) dp[i][j]=0;
	dp[0][0]=1;
	rb(i,1,n/2){
		rb(j,1,min((int)(B.length()-1),i)){
			if(r_s[i]==B[j]){
				dp[i][j]+=dp[i-1][j-1];
			}
			if(r_s[i]==A[i-j]){ 
				dp[i][j]+=dp[i-1][j];
			}
		}
	}
	return dp[n/2][B.length()-1];
}	string s;
void dfs1(string A,string B,int now){
	if(now>(n>>1)){
		res+=check(A,B);
	}
	else{
		dfs1(A+s[now],B,now+1);
		dfs1(A,B+s[now],now+1);
	}
}
int main(){
	cin>>n;
	n=n+n;
	cin>>s;
	s='$'+s;
	rl(i,n,n/2+1) r_s+=s[i];r_s='%'+r_s;
	dfs1("","",1);
	cout<<res+res<<endl;
	return 0;	
}
