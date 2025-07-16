/* Author : Aaryan Srivastava ^__^ */ 
#include <bits/stdc++.h>
#include <random>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define pb push_back
#define popb pop_back
#define mt make_tuple 
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second 
#define ull unsigned long long  
#define pii pair<int, int>
#define piii pair<int,pii>
#define beg begin
#define rep(i,n) for(int (i) = 0 ; i < (n) ; i++)
#define repA(i,x,y) for(int i = (x) ; i <= (y) ; i++)
#define repD(i,x,y) for(int i = (x) ; i >= (y) ; i--)
#define all(c) (c).begin(),(c).end()
#define fill(a,val) memset(a,val,sizeof(a))
#define Randomize mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define int ll
using ll = long long;
const int N = 4e6 +5 ;
const int mod = 1e9 + 7 ;
const int inf = 1e18 ;
const int SZ = 101 ;
const double eps = 1e-9 ;
using namespace __gnu_pbds;
using namespace std;
using ordered_set =  tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ;

#ifdef AaryanS
#define mycout cout
#define mycerr cerr 
#endif

#ifndef AaryanS
#define mycout if(false) cout
#define mycerr if(false) cerr
#endif

const int M = 2005 ;
// l = 0 , r = 1 , u = 2 , d = 3 , no = 4;
int dx[] = {0 , 0 , -1 , 1};
int dy[] = {-1, 1 , 0 , 0};
int ad[5][M][M];
int g[M][M] ;

int ok(int i , int j , int n , int m){
	bool ans1 = (i >= 0 && i < n);
	bool ans2 = (j >= 0 && j < m);
	return ans1 && ans2 ;
}

int sqsum(int k , int lx , int ly , int rx , int ry){
	int res = ad[k][rx][ry]; 
	if(lx) res -= ad[k][lx-1][ry];
	if(ly) res -= ad[k][rx][ly - 1];
	if(lx && ly) res += ad[k][lx-1][ly-1];
	return res ;
}
void solve()
{
	int n , m , q ;
	cin >> n >> m >> q;
	string s[n] ;
	rep(i , n){
		cin >> s[i] ;
		rep(j , m)
			g[i][j] = s[i][j] - '0';
	}
	rep(i , n) rep(j , m){
		if(g[i][j]){
			rep(k , 4) ad[k][i][j] = (ok(i + dx[k] , j + dy[k] , n , m) && g[i + dx[k]][j + dy[k]]);
		}
		ad[4][i][j] = g[i][j];
	}
	rep(k , 5){
		rep(i , n) rep(j , m){
			if(i) ad[k][i][j] += ad[k][i-1][j] ;
			if(j) ad[k][i][j] += ad[k][i][j-1] ;
			if(i && j) ad[k][i][j] -= ad[k][i-1][j-1];
		}
	}
	while(q--){
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry; 
		lx--, ly--, rx--, ry-- ;
		int edges = 0;
		rep(k , 4) edges += sqsum(k , lx , ly , rx , ry); 
		edges -= sqsum(0 , lx , ly , rx, ly);
		edges -= sqsum(1 , lx, ry, rx, ry);
		edges -= sqsum(2 , lx , ly , lx, ry);
		edges -= sqsum(3 , rx, ly, rx, ry);
		int nodes = sqsum(4, lx, ly, rx, ry);
		// cout << nodes << " " << edges/2 << "\n" ;
		cout << nodes - edges/2 << "\n" ;
	}

}   

     
int32_t main(int32_t argc, char *argv[])
{
    double t1 = clock() ;
    ios::sync_with_stdio(0);    
    cin.tie(0); cout.tie(0);
    int TC = 1, t = 0;
    //cin >> TC ;
    while(t++ < TC)
    {
        //cout << "Case #" << t << ": " ;
        solve();
        //cout << endl ;
    }
    mycerr << "Time : " << 1000 *(clock() - t1)/CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}