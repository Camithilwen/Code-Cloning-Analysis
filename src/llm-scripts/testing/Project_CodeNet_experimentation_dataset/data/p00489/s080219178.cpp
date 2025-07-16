#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#define rep(i,l,n) for(lint i=l;i<n;i++)
#define rer(i,l,n) for(lint i=l;i<=n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef vector<int> vi;
typedef vector<lint> vli;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int main(){
	int n;
	cin>>n;
	vi d(n);
	int f,l,sf,sl;
	rep(i,0,n*(n-1)/2){
		cin>>f>>l>>sf>>sl;
		f--;
		l--;
		if(sf<sl){
			d[l]+=3;
		}else if(sf>sl){
			d[f]+=3;
		}else{
			d[l]++;
			d[f]++;
		}
	}
	vi e=d;
	sort(all(e));
	rep(i,0,n){
		int res=upper_bound(all(e),d[i])-e.begin();
		o(n+1-res);
	}
}