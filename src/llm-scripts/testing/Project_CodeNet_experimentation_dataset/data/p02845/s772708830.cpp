#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;
const ll modP = 1000000007;


int main()
{
	int n;
	cin>>n;
	vector<ll> A(n);
	rep(i,n) cin>>A[i];
	vector<ll> x(n+1,0);
	vector<ll> y(n+1,0);
	vector<ll> z(n+1,0);
	for(int i = 0; i < n; i++){
		x[i+1] = x[i];
		y[i+1] = y[i];
		z[i+1] = z[i];
		if( A[i] == x[i]){
			x[i+1]++;
		}else if(A[i] == y[i]){
			y[i+1]++;
		}else{
			z[i+1]++;
		}
	}
	ll ans = 1;
	for(int i = 0; i < n; i++){
		int t = 0;
		if( x[i] == A[i]) t++;
		if( y[i] == A[i]) t++;
		if( z[i] == A[i]) t++;
		ans = (ans * t) % modP;
	}
	cout<<ans<<endl;
	return 0;
}
