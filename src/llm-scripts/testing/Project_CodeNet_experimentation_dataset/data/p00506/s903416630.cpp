#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<cmath>
#include<ctime>
#include<complex>

using namespace std;

#define REP(i,s,e) for(int i=int(s);i<=int(e);i++)
#define rep(i,n) for(int i=0;i<int(n);i++)

int g(int a,int b){
	int c=max(a,b),d=min(a,b);
	if(c%d==0) return d;
	else return g(d,c%d);
}
int main(){

	int n,p,q,r;
	cin >> n;

	if(n==2){
		cin >> p >> q;

		REP(i,1,g(p,q))
		if(g(p,q)%i==0) cout << i << endl;

	}

	if(n==3){
		cin >> p >> q >> r;

		REP(i,1,g(g(p,q),r))
		if(g(g(p,q),r)%i==0) cout << i << endl;

	}

	return 0;
}