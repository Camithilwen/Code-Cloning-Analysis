#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <complex>
using namespace std;

#define ll long long
#define vvi vector< vector<int> >
#define vi vector<int>
#define All(X) X.begin(),X.end()
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define pi 3.14159265359
#define shosu(X) fixed << setprecision(X)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
	const int intmax  = 1000010;
	ll int e;
	while(cin >> e,e){
		ll int ans = 9999999;
		FOR(y,0,sqrt((double)e)+2){
			FOR(z,0,cbrt((double)e)+2){
				if(e-y*y-z*z*z>=0) ans = min(ans,y+z+(e-y*y-z*z*z));
			}
		}
		cout << ans << endl;
	}
	
}