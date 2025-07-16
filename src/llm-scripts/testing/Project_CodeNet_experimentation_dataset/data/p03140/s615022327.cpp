#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

#define P pair<lli,lli>

signed main(){

	lli n;
	cin>>n;

	string s[3];
	REP(i,0,3)cin>>s[i];

	lli cnt = 0;
	REP(i,0,n){
		set<char> c;
		REP(j,0,3){
			c.insert(s[j][i]);
		}
		if(c.size()==3)cnt+=2;
		else if(c.size()==2)cnt++;
	}

	cout<<cnt<<endl;

	return 0;
}