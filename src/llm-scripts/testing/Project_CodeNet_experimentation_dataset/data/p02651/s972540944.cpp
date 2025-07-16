#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
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

int q,n;
vl a;
string s;

int main(){
	cin>>q;
	while(q){
		cin>>n;
		a=vl(n);
		for(auto &i:a) cin>>i; 
		cin>>s;
		reverse(a.begin(),a.end());
		reverse(s.begin(),s.end());
		vl b;
		bool B=0;
		for(int i=0;i<n;i++){
			ll x=a[i];
			for(auto j:b) x=min(x,x^j);
			if(s[i]=='0') b.push_back(x);
			else if(x) B=1;
		}
		cout<<B<<endl;
		q--;
	}
}