#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
#include <iomanip>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	ll n;
	cin >> n;
	vector<ll> a(n), b(n), c(n);
	REP(i,n) cin >> a[i];
	REP(i,n) cin >> b[i];
	REP(i,n) cin >> c[i];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	
	vector<ll> B(n),SB(n+1);
	REP(i,n){
		if(b[i] >= c[n-1]){
			B[i] = 0;
			continue;
		}
		int ok,ng,mid;
		ok = 1;
		ng = n+1;
		while(abs(ok-ng)>1){
			mid = (ok+ng)/2;
			if(b[i]<c[n-mid]){
				ok = mid;
			}else{
				ng = mid;
			}
		}
		B[i] = ok;
	}
	
	SB[n]=0;
	for(int i=n-1; i>=0; i--) SB[i] = SB[i+1]+B[i];
	
	vector<ll> A(n);
	REP(i,n){
		if(a[i] >= b[n-1]){
			A[i] = 0;
			continue;
		}
		int ok,ng,mid;
		ok = 1;
		ng = n+1;
		while(abs(ok-ng)>1){
			mid = (ok+ng)/2;
			if(a[i]<b[n-mid]){
				ok = mid;
			}else{
				ng = mid;
			}
		}
		A[i] = SB[n-ok];
	}
	
	ll ans = 0;
	REP(i,n) ans += A[i];
	cout << ans << endl;
	
	return 0;
}