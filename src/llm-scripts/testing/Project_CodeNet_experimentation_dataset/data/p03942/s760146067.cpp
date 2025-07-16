#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
char a[1000005],b[1000005];
vector<int>from;
vector<int>to;
vector<int>pos[26];
int main(){
    int n;
	scanf("%d%s%s",&n,&a,&b);
	for(int i=0;i<n;i++) if(a[i] != b[i]) goto nxt;
	puts("0"); return 0; nxt:;
	for(int i=0;i<n;i++) pos[a[i]-'a'].pb(i);
	bool dif = 0;
	int pre = INF;
	for(int i=n-1;i>=0;i--){
		if(i == 0 || (i > 0 && b[i-1] != b[i])){
			int id = b[i]-'a';
			int x = POSU(pos[id],min(pre-1,i));
			if(x == 0){
				puts("-1");
				return 0;
			}
			from.pb(pos[id][x-1]);
			to.pb(i);
			if(pos[id][x-1] != i) dif = 1;
			pre = pos[id][x-1];
		}
	}
	int ret = 0;
	for(int i=0;i<to.size();i++){
		//(lb,ub]
		int lb = -1,ub = i+1;
		while(ub-lb > 1){
			int mid = (lb+ub)/2;
			int x = from[i-mid]-mid;
			if(x >= to[i]) ub = mid;
			else lb = mid;
		}
		ret = max(ret,ub+1);
	}
	cout<<ret<<endl;
}