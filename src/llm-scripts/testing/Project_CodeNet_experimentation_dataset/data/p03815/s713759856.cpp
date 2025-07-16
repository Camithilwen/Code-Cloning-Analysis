#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int main(){
	ll x;cin>>x;
	if(x<=6) puts("1");
	else if(x<=11) puts("2");
	else {
		ll y=x/11,z=x%11;
		y<<=1;
		if(z>0&&z<=6) y++;
		else if(z>0&&z>6) y+=2;
		cout<<y;
	}
	return 0;
}