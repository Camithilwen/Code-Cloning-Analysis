#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n;
char a[3][3];
char b[4][4];

string c[5];
int main(){
	a[0][0] = 'a'; a[0][1] = 'a'; a[0][2] = 'c';
	a[1][0] = 'b'; a[1][1] = '.'; a[1][2] = 'c';
	a[2][0] = 'b'; a[2][1] = 'd'; a[2][2] = 'd';


	b[0][0] = 'a'; b[0][1] = 'a'; b[0][2] = 'c'; b[0][3] = 'd';
	b[1][0] = 'b'; b[1][1] = 'b'; b[1][2] = 'c'; b[1][3] = 'd';
	b[2][0] = 'c'; b[2][1] = 'd'; b[2][2] = 'a'; b[2][3] = 'a';
	b[3][0] = 'c'; b[3][1] = 'd'; b[3][2] = 'b'; b[3][3] = 'b';


	c[0] = "a.eef";
	c[1] = "ab..f";
	c[2] = ".bggi";
	c[3] = "cch.i";
	c[4] = "ddhjj";

	int n;
	cin >> n;
	if(n<=2) puts("-1");
	else if(n == 7){
		cout <<
		"aa...bc" << endl <<
		"....dbc" << endl <<
		"eeffd.." << endl <<
		".abbcc." << endl <<
		".a..edd" << endl <<
		"g...e.f" << endl <<
		"g.hh..f" << endl;
	}
	else if(n == 11){
		cout <<
		"aa.......bc" << endl <<
		"........dbc" << endl <<
		"aabb....d.." << endl <<
		"c...ddee..." << endl <<
		"c......aabb" << endl <<
		".cde......." << endl <<
		".cde......." << endl <<
		"....abc...." << endl <<
		"....abc...." << endl <<
		"..dd..ee..c" << endl <<
		"....aa..bbc" << endl;

	}
	else if(n%3 == 0){
			string ans[1005];
			rep(i,n) rep(j,n) ans[i].pb('.');
			rep(i,n/3){
				int x = i*3, y = i*3;
				rep(aa,3)rep(b,3){
					ans[x+aa][y+b] = a[aa][b];
				}
			}
			rep(i,n) cout << ans[i] << endl;
		
	}
	else{
			string ans[1005];
			rep(i,n) rep(j,n) ans[i].pb('.');
			rep(aaa,n) rep(bbb,n){
				if(4*aaa+5*bbb == n){
					int cur = 0;
					rep(i,aaa){
						rep(aa,4)rep(bb,4) ans[cur+aa][cur+bb] = b[aa][bb];
						cur += 4;
					}
					rep(i,bbb){
						rep(aa,5)rep(bb,5) ans[cur+aa][cur+bb] = c[aa][bb];
						cur += 5;
					}
					rep(i,n) cout << ans[i] << endl;return 0;
				}
			}
		
	}
}