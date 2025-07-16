 #include<bits/stdc++.h>
 #include <ext/pb_ds/tree_policy.hpp>
 #include <ext/pb_ds/assoc_container.hpp>
 #include<chrono>
 using namespace std;
 using namespace std::chrono;      
 using namespace __gnu_pbds; 
 #define fastio     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 #define fi         first
 #define se         second
 #define int         long long 
 #define pb         push_back
 #define emp        emplace_back
 #define vv(x)      vector<x>
 #define mp(x,y)    map<x,y>
 #define dq(x)      deque<x>
 #define pql(x)     priority_queue<x>
 #define pqs(x)     priority_queue<x,vv(x),greater<x> >
 #define M          998244353
 #define forf(i,a,b) for(int i=a;i<b;i++)
 #define it(x)      x::iterator
 #define ll         long long 
 #define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
 #define time__(d)  for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
 #define vii        vector<int>
 #define big        3e18
 #define sm         -1e9
 #define mkr        make_pair
 #define vpi        vector<pair<int,int> >
 #define pii        pair<int,int>
 #define rng        500005
 #define sz(x)      (int)x.size()
 #define rv(x)      reverse(x.begin(),x.end())
 #define out(x)     cout<<x.fi<<" "<<x.se<<endl;

 typedef tree<pii, null_type, less<pii>, rb_tree_tag,  
            tree_order_statistics_node_update>  odst; 


void pr_init()
{
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   
    #endif
}


pair<int,pii> proc (string s)
{
  int an = 0 , lef = 0 , rg = 0;;

  for(int i=0;i<sz(s);i++)
  {
    if(s[i]=='(') an--;
    else an++;
    lef = max(lef,an);
  }
  
  an = 0;
  for(int i=sz(s)-1;i>=0;i--)
  {
    if(s[i]=='(')an++;
    else an--;
    rg = max(rg,an);
  }

  return {lef,{rg,an}};
  
}

int arr[1000001],vis[1000001];
void solve()
{
 
 int n;
 
 cin >> n;
 
 vector<pair<int,pii> >  sq;
  
 vpi lef,rg;
 for(int i=0;i<n;i++)
 {
   string s;
   cin >> s;
   pair<int,pii> rm = proc(s);
   //cout<<rm.fi<<" "<<rm.se.fi<<" "<<rm.se.se<<endl;
   lef.pb({rm.fi,i});
   rg.pb({rm.se.fi,i});
   arr[i] = rm.se.se;
 }
 

 sort(lef.begin(),lef.end());
 sort(rg.begin(),rg.end());

 int i = 0,j=0,fw=0,bk=0,fl=0;


 while(i<sz(lef) && j<sz(rg))
 {
    if(vis[lef[i].se]) i++;
    else if(vis[rg[j].se]) j++;
    else
    {
      if(fw - lef[i].fi < 0 || bk + rg[j].fi > 0) fl=1;
      fw += arr[lef[i].se];
      vis[lef[i].se] =1;
      i++;
      if(!vis[rg[j].se]) bk += arr[rg[j].se] , vis[rg[j].se]=1;
      j++;
    }
 }


 
 if(fl || (fw+bk)!=0)
 {
   cout<<"No\n";
 }
 else  cout<<"Yes\n";

}

int32_t main()
{
 pr_init();
  fastio;
  
  auto start = high_resolution_clock::now(); 
 
  solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start); 
  
    // cout << "Time taken by function: "
    //      << duration.count() << " microseconds" << endl; 

 }