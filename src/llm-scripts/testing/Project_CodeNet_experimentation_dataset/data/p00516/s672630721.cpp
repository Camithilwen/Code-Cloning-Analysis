#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;

int a[1000];
int b[1000];
int c[1000];

int main(){
	int n, m;
	
	cin >> n >> m;
	
	REP(i,n){
		scanf("%d", &a[i]);
	}
	
	REP(i,m){
		scanf("%d", &b[i]);
	}
	
	REP(i,m){
		REP(j,n){
			if (a[j] <= b[i]){
				c[j]++;
				break;
			}
		}
	}
	
	int ma = 0;
	int ans;
	
	REP(i,n){
		if (c[i] > ma){
			ma = c[i];
			ans = i+1;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}