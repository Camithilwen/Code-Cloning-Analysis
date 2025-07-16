#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("Ofast")
//*********************************************DO IT NOW****************************************************************
#include<bits/stdc++.h> 
#include<random>
#define int long long   
#define pp pair<int,int> 
#define ss second 
#define ff first 
#define pb push_back
#define mod 1000000007
#define pi 3.14159265359
#define mk(arr,n,type)  type *arr=new type[n];
#define sl s1.length();
#define yes cout<< "YES"<<endl
#define no  cout<< "NO"<<endl
#define all(v) (v).begin(),(v).end()
#define s(v)   sort(v,v+n)
#define  mt mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define read(a,n) for(int i=0;i<n;i++)cin>>a[i]
#define print(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" "
using namespace std;
//**********************************************DO IT NOW***************************************************************
void fastio()
{  
  #ifndef ONLINE_JUDGE
  freopen("INPUT.txt","r",stdin);
  freopen("OUTPUT.txt","w",stdout); 
  #endif
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL) ; 
  cout.tie(NULL);
}
int dp[101][1001],ans1=1e9,dp1[1000001];
int num[10];
int a[1000000];
int prime(int n)
{
 for(int i=2;i*i<=n;i++)
      {
          if(n%i==0)
          return 0;
      }
      return 1;
}
signed main()
{   
    fastio();
    int t=1;
   // cin>>t;
    while(t--)
    {  
       int a,b,c;
       cin>>a>>b>>c;
       int x=0;
       if(a==c && c!=b)
       x++;
       if(a==b && b!=c)
       x++;
       if(b==c && c!=a)
       x++;
       if(x)
       cout<<"Yes";
       else
       cout<<"No";
    }
    
}
// 🍪 🍪 🍪
