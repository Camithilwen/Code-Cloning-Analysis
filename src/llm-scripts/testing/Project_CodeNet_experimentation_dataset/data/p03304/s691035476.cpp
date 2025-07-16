#pragma GCC optimize("Ofast")
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

const long long INF_L = 1e17+7;
const long long INF_I = 1e9+7;
const long long MOD = 1e9+7;
const double EPS = 1e-8;
const double PI=acos(-1);

using namespace std;

int main(){	
	
	long long n,m,d;
	cin >> n >> m >> d;
	long double ans;
	
	if(d>0){
		ans=(double)(m-1)*(2*(double)(n-d)/(double)(pow(n,2)));
	}else if(d==0){
		ans=(double)(m-1)*((double)1/(double)(pow(n,1)));
	}
	
	cout << fixed << setprecision(10) << ans << endl;
	
	return 0;
}