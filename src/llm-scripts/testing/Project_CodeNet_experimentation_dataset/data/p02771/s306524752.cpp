#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>


#define int  long long
#define rep(i,begin,end) for(__typeof(end)i=(begin)-((begin)>(end));i!=(end)-((begin)>(end));i+=1-2*((begin)>(end)))
#define F first
#define S second
#define sz(x) ((int)x.size())
#define pb push_back
#define pf push_front
#define eb emplace_back 
#define all(v) (v).begin(), (v).end()
#define mod 1000000007
#define mod2 998244353
#define what_is(x) cerr << #x << " is " << x <<"\n";
#define sortA(v) sort(v.begin(), v.end())
#define sortD(v) sort(v.rbegin(), v.rend())
#define PI 3.14159265358979323846
#define vout(a) for(auto x:a) cout<<x<<" ";
#define INF 1000000000000

// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>


// using namespace __gnu_pbds;
using namespace std;

using ll  = long long;
using vi  = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vii = vector<pii>;
using mi  = multiset<int>;
using mii = multiset<pii>;

int lcm(int a,int b) {return (a*(b/__gcd(a,b)));}



void solve()
{
    int n,m,t,i,l,k,r,u,v,w,j,s,sum=0,pos,flag=0,count=0;
    string S,T,U;
    // int x,y,a,b,c;
    cin>>n>>m>>k;
  set<int> a;
 a.insert(n);
  a.insert(m);
  a.insert(k);
  if(sz(a)==2) cout<<"Yes";
  else cout<<"No";
}


signed main()
{

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    int T=0;
    while(t--)
    {
        T++;
        // if(T>1) cout<<"\n";
        // cout<<"Case #"<<T<<": ";
        solve();
        if(t)cout<<"\n";
    }
    return 0;
}