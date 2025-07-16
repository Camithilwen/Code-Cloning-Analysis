#include <bits/stdc++.h>
// #define int long long
#define Matrix vector<vector<int> >
// #define Matrix vector<vector<int> >
#define double long double
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define td(v) v.begin(),v.end()
#define tdr(v) v.rbegin(),v.rend()
#define endl "\n"
#define Matrix vector<vector<int> >
using namespace std;
const int MOD = 1e9+7;
const long long INF = 5e18;
const double pi = acos(-1.0);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
 
inline long long mod(long long n, long long m){
    long long ret = n%m;
    if(ret < 0) ret += m;
    return ret;
}
 
double rad(double x){
    return x*pi/180.0;
}
 
bool isleft(pair<int,int> a, pair<int,int> b, pair<int,int> c){
    int det = (b.first-a.first)*(c.second-a.second) - (c.first-a.first)*(b.second-a.second);
    if(det>=0) return true;
    if(det<0) return false;
    return false;
}
 
int exp(int a, int b){
    int result = 1;
    while (b > 0){
        if (b & 1)
            result = mod(result*a,MOD);
 
        b >>= 1;
        a = mod(a*a,MOD);
    }
    return result;
}

double memo[321][321][321];
int vet[321];
int n;
double dp(int t, int d, int u){
	if(t+d+u==0) return 0;
	double &x = memo[t][d][u];
	if(x!=-1) return x;
	x = 0;
	if(t>0)
		x+=t*dp(t-1,d+1,u);
	if(d>0)
		x+=d*dp(t,d-1,u+1);
	if(u>0){
		x+=u*dp(t,d,u-1);
	}
	x/=(t+d+u)*1.0;
	x+=n*1.0/(t+d+u);
	return x;
}
void solve(){
	cin>>n;
	int q[4] = {0,0,0};
	for(int i=0;i<n;i++){
		cin>>vet[i];
		q[vet[i]]++;
	}
	for(int i=0;i<321;i++)
		for(int j=0;j<321;j++)
			for(int k=0;k<321;k++)
				memo[i][j][k]=-1;
	cout<<fixed<<setprecision(13);
	cout<<dp(q[3],q[2],q[1])<<endl;
}

signed main(){
    fastio;
    int t=1;
    // cin>>t;
    while(t--)
        solve();
}
