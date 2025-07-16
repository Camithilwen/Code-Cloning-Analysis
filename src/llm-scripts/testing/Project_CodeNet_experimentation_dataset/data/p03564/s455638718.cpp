
#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

 int main()
{

 long long n,k,sum=0;
 cin>>n>>k;

 long long ans = 1;

  while(n--){

  long long ans2 = ans*2;
  long long ani = ans+k;

  if(ans2 < ani)
    ans = ans2;
  else ans = ani;

  }

  cout<<ans<<endl;

 return 0;
}
