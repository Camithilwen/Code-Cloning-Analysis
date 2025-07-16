#include<bits/stdc++.h> 
#include<random>
#define int long long   
#define pp pair<int,int> 
#define ss second 
#define ff first 
#define pb push_back
#define mod 1000000007
#define mk(arr,n,type)  type *arr=new type[n];
#define sl s1.length();
#define yes cout<< "Yes"<<endl
#define no  cout<< "No"<<endl
#define all(v) (v).begin(),(v).end()
#define  mt mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;    
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
signed main()
{   
    fastio();
    int t=1;
   // cin>>t;
    while(t--)
    {    
       
      int a[3];
      for(int i=0;i<3;i++)
      cin>>a[i];
      sort(a,a+3);
      cout<<a[0]+a[1];
       
    }
}


// 🍪 🍪 🍪