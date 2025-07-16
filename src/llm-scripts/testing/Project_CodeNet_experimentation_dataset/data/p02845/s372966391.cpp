//q098.cpp
//Wed Sep 16 20:16:46 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n;
	cin >> n;

	ll ans = 1;
	vector<int> count(3,0);
	rep(i,n){
		ll a;
		cin >> a;
		ll tmp = 0;
		ll flag = 1;
		rep(j,3){
			if(count[j]==a){
				tmp++;
				if(flag){
					count[j]++;
					flag = 0;
				}
			}
		}
		ans = ans*tmp%MOD;
	}


	cout << ans << endl;
//	printf("%.4f\n",ans);
}