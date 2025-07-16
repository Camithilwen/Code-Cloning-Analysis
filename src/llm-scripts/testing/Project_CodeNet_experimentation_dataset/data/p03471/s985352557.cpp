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
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int n,y;
	cin >> n >> y;
	
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			int k = n - (i+j);
			if(k < 0) continue;
			if(y == 10000*i + 5000*j + 1000*k){
				printf("%d %d %d\n",i,j,k);
				return 0;
			} 
		}
	}
	
	printf("-1 -1 -1\n");
	
	return 0;
}