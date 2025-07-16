#include<bits/stdc++.h>
typedef long long int ll;
#define pb push_back
#define pi  3.141592653589793238462643383279
#define int long long
#define ff first
#define ss second
#define endl '\n'
#define inf 21474836478965499999
#define all(x) (x).begin(), (x).end()
#define rep(i,x,y) for(int i=(int)x; i<y; i++)
#define high_functioning_sociopath  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const unsigned int M = 1000000007;
/*------------------------------------- THE GAME IS ON ---------------------------------------------*/
void solve()
{
     int n; cin>>n;
     queue<int>q;
     for(int i=0;i<n;i++)
     {
            int x;
            cin>>x;
            q.push(x);
     }
     int ht=0;
     int prev=q.front();
     q.pop();
     while(q.size()>0)
     {
            int temp=q.front();
            ht+=max(ll(0),prev-temp);
            prev=max(temp,prev);
            q.pop();
     }
     cout<<ht<<endl;
}       
int32_t main()
{
   high_functioning_sociopath
   ll t=1;
   //cin>>t;
   while(t--)
   {
      solve();
   }
}