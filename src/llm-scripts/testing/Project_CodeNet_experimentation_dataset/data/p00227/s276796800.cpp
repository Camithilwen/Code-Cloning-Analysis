#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

int main(){
	while(1){
		int n, m;
		cin>>n>>m;
		if(n==0) break;
		int a[n];
		REP(i, n) cin>>a[i];
		sort(a, a+n, greater<int>());
		int sum = 0;
		REP(i, n) sum+=a[i];
		for(int i=m-1; i<n; i+=m){
			sum-=a[i];
		}
		printf("%d\n", sum);
	}
}