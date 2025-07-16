#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <complex>
#include <map>
#include <climits>
#include <sstream>
using namespace std;

#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define EPS 1e-8
#define F first
#define S second
#define mkp make_pair

static const double PI=6*asin(0.5);
typedef long long ll;
typedef complex<double> CP;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vint;
static const int INF=1<<24;

template <class T>
void initvv(vector<vector<T> > &v,int a,int b, const T  &t = T()){
	v.assign(a,vector<T>(b,t));
}

//v.erase(unique(v.begin(),v.end()),v.end());


int main(){
	int n;
	cin>>n;
	vector<ll> v(n,1);
	rep(i,n) cin>>v[i];
	ll tt=v[0];
	rep(i,n){
		tt=min(v[i],tt);
	}
	// cout<<tt<<endl;
	rep(i,tt){
		bool f=true;
		rep(j,n){
			if(v[j]%(i+1)==0) continue;
			else{
				f=false;
				break;
			}
		}
		if(f) cout<<i+1<<endl;
	}
}