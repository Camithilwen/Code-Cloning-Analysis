#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef double db;

#define fr first
#define sc second
#define pb push_back
#define rep(i,x) for(ll i=0;i<x;i++)
#define rep1(i,x) for(ll i=1;i<=x;i++)
#define rrep(i,x) for(ll i=x-1;i>=0;i--)
#define rrep1(i,x) for(ll i=x;i>0;i--)

ll ans=0;
ll n;
string s;
ll cnt=0;
P p[1000001];
ll sz;
int main()
{
	cin>>s;
	sz=0;
	n=s.length();
	rep(i,n){
		if(i==0){
			if(s[0]=='J') p[sz]=P(1,0);
			else if(s[0]=='O') p[sz]=P(1,1);
			else p[sz]=P(1,2);
			sz++;
		}
		else{
			if(s[i]!=s[i-1]){
				if(s[i]=='J') p[sz]=P(1,0);
				else if(s[i]=='O') p[sz]=P(1,1);
				else p[sz]=P(1,2);
				sz++;
			}
			else{
				p[sz-1].fr++;
			}
		}
	}
	rep(i,sz-2){
		if(p[i].sc==0&&p[i+1].sc==1&&p[i+2].sc==2&&p[i].fr>=p[i+1].fr&&p[i+1].fr<=p[i+2].fr){
			ans = max(ans , p[i+1].fr );
		}
	}
	cout<<ans<<endl;
}