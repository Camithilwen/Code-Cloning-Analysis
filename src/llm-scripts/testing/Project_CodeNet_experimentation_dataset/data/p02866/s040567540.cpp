#include<iostream>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<limits>
#include<sstream> 
#include<unordered_map>      

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef int itn;

const int inf = numeric_limits<int>::max() >> 2;
const ll linf = numeric_limits<ll>::max() >> 2;
const ull ulinf = numeric_limits<ull>::max() >> 2;
const double pi = acos(-1);
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const int dx8[8]={-1,0,1,-1,1,-1,0,1};
const int dy8[8]={-1,-1,-1,0,0,1,1,1};

#define p_queue(i) priority_queue<i> 
#define rp_queue(i) priority_queue<i, vector<i>, greater<i>> 
#define umap(i,j) unordered_map<i,j>
#define P(p) cout<<(p)<<endl
#define PS(p) cout<<(p)<< " "
#define PN cout << endl
#define rep(i,m,n) for(int i = (m); i < (int)(n); i++)
#define rrep(i,m,n) for(int i = (n-1); i >= (int)(m); i--)
#define inrep(n,a) for(int i = 0; i < (int)(n); i++)cin >> a[i];
#define mod(i) ((i)%(ll)( 998244353))
#define divm(a,b) (mod(a * modpow((ll)b,(ll)(1e9+5))))
#define rsort(a,b,c) sort(a, b, greater<c>())
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v,c) sort(v.begin(), v.end(), greater<c>()) 
#define ft first
#define sd second
#define pb push_back
#define it insert
#define sz(x) ((int)(x).size())
#define lb(a,n,k) (lower_bound(a,a+n,k) - (a)) 
#define vlb(a,k)  (lower_bound(a.begin(),a.end(),k) - a.begin())
#define ub(a,n,k) (upper_bound(a,a+n,k) - (a)) 
#define vub(a,k)  (upper_bound(a.begin(),a.end(),k) - a.begin())
#define YES cout<<"YES"<< endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl  
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define ret return


ll modpow(ll i,ll j){ ll tmp=1; while(j){ if(j%2)tmp=mod(tmp*i);i=mod(i*i);j/=2;}return tmp;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


/*
vector<string> split(const string &str, char sep){
    vector<string> v;
    stringstream ss(str);
    string buffer;
    while( getline(ss, buffer, sep) ) {
        v.push_back(buffer);
    }
    return v;
}
*/

/*
ll ncr[100][100];
ll nCr(int n, int r){if(n==r) ret ncr[n][r] = 1; if(r==0) ret ncr[n][r] = 1; if(r==1) ret ncr[n][r] = n;if(ncr[n][r]) ret ncr[n][r]; ret ncr[n][r] = nCr(n-1,r) + nCr(n-1,r-1);}

ll npr[100][100]={};
ll nPr(int n,int r){if(npr[n][r])ret npr[n][r];if(r==0)ret npr[n][r] = 1;if(r==1)ret npr[n][r] = n;ret npr[n][r] = n * nPr(n-1,r-1);}

ll nHr(int n,int r){ret nCr(n+r-1,r);}
*/

///////////////////////////////////////////////////////////////////////////



int main(){
    ll n;
    cin >> n;
    map<ll,ll> d;
    ll max_d= 0;
    
    rep(i,0,n){
	ll a;
	cin >> a;
	d[a]++;
	if(i == 0){
	    if(a != 0){
		P(0);
		ret 0;
	    }
	}
	max_d = max(max_d,a);
    }

    ll ans = 0;
    if(d[0] == 1){
	ans = 1;
	ll num = 1; 

	while(num <= max_d){
	 
	    ans *= modpow( d[num-1] , d[num]);
	    ans = mod(ans);
	    
	    num++;
	}

    }
    
    P(ans);
    
    return  0;
}
