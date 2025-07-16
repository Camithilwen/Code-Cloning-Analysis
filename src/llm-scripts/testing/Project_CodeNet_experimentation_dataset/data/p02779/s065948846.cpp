#include <bits/stdc++.h>
using namespace std;
#define END '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define trace(x) cerr<<x<<END;
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i) 
const int mod = 1e9+7;
const int mod1 = 998244353;
const int inf = 1e18;
set<int> s;
int n,x;
void solve()
 {
  cin>>n;
  loop(i,0,n)
   {
	   cin>>x;
	   s.insert(x);
	}
 cout<<((int)s.size() == n ? "YES" : "NO");
  
 }  
signed main()
 {   
  ios_base::sync_with_stdio(false);
  cin.tie(0); 
  cout.tie(0); 
   /*int t;
   cin>>t;
   loop(i,1,t+1)*/
      solve();
      
  //cerr<<END<<1.0*clock();
  return 0;
} 
