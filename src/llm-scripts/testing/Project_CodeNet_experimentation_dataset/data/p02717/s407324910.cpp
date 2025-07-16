#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,x,n) for(ll i=x;i<n;i++) 
#define sort(v) sort(v.begin(),v.end());
const ll mod = 1E9+7;

int main()
{
  ll a,b,c;
  cin>>a>>b>>c;
  swap(a,b);
  swap(a,c);
  cout<<a<<" "<<b<<" "<<c;
}