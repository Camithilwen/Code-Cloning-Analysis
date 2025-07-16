#include<iostream>
#include<queue>
#include<limits>
// #include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<cmath>
#include<math.h>
#include<iomanip>  
#include<deque> 
#include<stack>
#include<string> 
#include<string.h>
#include<map>
#include<set>
#include<unordered_map>
#include<utility>
#define ll long long
#define tc(t)  while(t--)
#define V vector
#define Vp vector< pair<int,int> >
#define pb push_back
#define UM unordered_map
#define IT iterator
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define PQ priority_queue
#define _FI ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

 char ar[140000];
vector<ll> SieveOfEratosthenes(ll n) 
{ 
  vector<ll> result;
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    int count=1;
    for (ll p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        {  
            for (ll i=p*p; i<=n; i += p) 
                {
                  prime[i] = false; 
                }
            count++;
        } 
    } 
  
    for (ll p=2; p<=n; p++) 
       if (prime[p]) 
          {
            result.push_back(p);
          }
    return result;
}



vector<ll> Divisors (ll n)
{
  vector<ll> res;
  for(ll i=1;i<=sqrt(n);i++)
  {
    if(n%i==0)
    {
      if(n/i==i)
      {
        res.pb(i);
      }
      else
      {
        res.pb(i);
        res.pb(n/i);
      }
    }
  }

  return res;
}

ll Div(ll n)
{
  for(ll i=2;i<=sqrt(n);i++)
  {
    if(n%i==0)
      return i;
  }
  return n;
}

int a[4][2]={ {1,0}, {1,-1}, {1,1}, {2,0} } ;
bool validPoint(int x,int y, int N)
{
    return (x>=0 && x<N && y>=0 && y<N);
}

 
int main()
{
  _FI 

  ll n;
  cin>>n;

  V<ll> arr(n);
  map<ll,ll> mp;
  forn(i,n)
    {
      cin>>arr[i];
      mp[arr[i]]++;
    }
    if(mp.size()==n)
    {
      cout<<"YES";
    }
    else
    {
      cout<<"NO";
    }
  

  return 0;
}













