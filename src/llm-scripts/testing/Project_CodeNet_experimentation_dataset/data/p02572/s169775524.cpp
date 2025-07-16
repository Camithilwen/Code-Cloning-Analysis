#include<bits/stdc++.h>
//#include<pair>
using namespace std;

typedef long long ll;
typedef int ii;
//typedef vector<ll> vi;

#define INF 1000000007

#define pi 3.141592654

#define T while(t--)
#define for2(i,a,b) for(i=a;i>=b;i--)
#define for3(i,a,b) for(i=a;i<=b;i=i+2)
#define for1(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mp make_pair

#include<sstream>

#define si set<ll>
#define se multiset<ll>

typedef long double ld;

typedef vector<int64_t> vi;

#define bb(arr,nn,xx) upper_bound(arr,arr+nn,xx)-arr
#define aa(arra,nna,xxa) lower_bound(arra,arra+nna,xxa)-arra

#define all(v) sort(v.begin(),v.end())
 
#define all1(v) sort(v.rbegin(),v.rend())

ii main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int64_t n,i; cin>>n; vi v; ll x;
    
    for1(i,1,n)
    {
    
        cin>>x;
       
        v.pb(x);
        
    }
    
    ll sum1=0; ll sum=0;
    
    for2(i,n-1,1)
    {
    
        sum1+=v[i];
        
        sum+=(((v[i-1]%INF)*(sum1%INF))%INF)%INF;
        
    }
    
    
   
    cout<<sum%(INF)<<"\n";
    
}
