
#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

#define pi 2*acos(0.0)


int main(void)
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    // cout.tie(0);
  set<ll>s;

  int n;
  cin>>n;
  bool flag = true;
  while(n--)
  {
      ll x;
      cin>>x;
      if(s.count(x)>0)
      {
          flag = false;
      }
      s.insert(x);
  }
  if(flag)
  {
      cout<<"YES"<<endl;
  }
  else
  {
      cout<<"NO"<<endl;
  }
}
