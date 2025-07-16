                                      // Believe in yourself
#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Pair vector<pair<ll,ll>>
#define vec vector <ll> 
#define all(a) a.begin(),a.end()
#define mo 1000000007
#define decimal(i,n) fixed << setprecision(i) << n
#define show(a) for(auto xyz:a)cout<<xyz<<" ";cout<<endl;
#define show_nl(a) for(auto xyz:a)cout<<xyz<<endl;


void eea(ll a,ll b,ll &x,ll &y)
{
    if (a == 1)
    {
        x = 1; y = 0;
        return;
    }
    ll x1, y1;
    eea(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
}
ll mi(ll a,ll m)
{
    ll x,y;
    eea(a,m,x,y);
    x= (x%m+m)%m;
    return x;
}

/*
Enter the test case


Some helpful points
1.) Calm yourself
2.) check for semicolon or data type mismatch
*/


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    ll t=1;
    // cin>>t;
    while(t--)
    {
       int n,k;
       cin>>n>>k;
       double a[n];
       double s=0;
       double ans=0;
       for(int i=0;i<n;i++)
       {
           cin>>a[i];
           a[i]=a[i]+1;
       }
       for(int i=0;i<k;i++)
       s=s+a[i];
       for(int i=k;i<n;i++)
       {   
           if(ans<s)
           ans=s;
           s=s-a[i-k]+a[i];
       }
       if(ans<s)
           ans=s;
       cout<<decimal(9,ans/2)<<"\n";
    }
}

