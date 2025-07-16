/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <stack>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <functional>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi   vector<int> 
#define   co(x)  cout << x << '\n' 
#define   dbg(x)  cerr << #x << " = " << x << '\n' 
#define   bitcount(x)  (int)__builtin_popcount(x) 
#define   sz(x)  (int)x.size()
#define   all(a) a.begin(),a.end() 
#define   ff   first
#define   ss   second
#define   inf  1000000007;
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

int  I[100005],L[100005];

inline void solve(){
    int n; cin>>n; 
    int  a[n+1], lis = 0 ; 
    I[0] = -inf ; 
    for (int i=1;i<=n;i++){
    	cin >> a[i] ; 
    	I[i] = inf ; 
    	L[i] = 1 ; 
    } 
    reverse (a+1,a+n+1);
    for (int i=1;i<=n;i++) { 
    	int  l = 0, r = lis ; 
    	while (l <= r){ 
    		int  mid = ( l + r ) >> 1 ; 
    		if (I[mid] <= a[i]) l = mid + 1 ; 
    		else r = mid - 1 ; 
    	} 
    	I[l] = a[i] ; 
    	if (l > lis) lis = l ; 
    }
    co (lis) ; 
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
