#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int


int main(){
ll x;
cin>>x;
ll ans=x/5.5;
if(2*x%11==0||2*(x+5)%11==0)
cout<<ans<<endl;
else
{
  cout<<ans+1<<endl;
}


  return 0;
}
