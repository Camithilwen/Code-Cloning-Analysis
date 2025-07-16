#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;

int c[10];

int main(){
	int n;
	
	while (cin >> n, n){
		REP(i,10) c[i] = 0;
		
		REP(i,n){
			int a;
			
			scanf("%d", &a);
			
			c[a]++;
		}
		
		REP(i,10){
			if (c[i] == 0) printf("-\n");
			else {
				REP(j,c[i]) printf("*");
				puts("");
			}
		}
	}
	
	return 0;
}