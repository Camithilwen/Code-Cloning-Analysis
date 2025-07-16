#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
 
using namespace std;
 
#define rep(i,n) for(int i=0; i<(n); i++)
#define repc(i,s,e) for(int i=(s); i<(e); i++)
#define pb(n) push_back((n))
#define mp(n,m) make_pair((n),(m))
#define all(r) r.begin(),r.end()
#define fi first
#define se second
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
 
 
 
const int INF = 1000000;
 

int main(){
	int n, m;
	cin>>n>>m;
	vi v(n, 0);
	vi u(n, 0);
	for(int i = 0; i < n; i++) cin>>v[i];
	int a;
	for(int i = 0; i < m; i++){
		cin>>a;
		for(int i = 0; i < n; i++){
			if(v[i] <= a){
				//cout<<" "<<i;
				u[i]++;
				break;
			}
		}
	}
	//cout<<endl;
	int ans = 0;
	for(int i = 1; i < n; i++){
		if(u[ans] < u[i]) ans = i;
	}
	cout<<ans+1<<endl;
}