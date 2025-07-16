#include <iostream>
using namespace std;
 
int main(){
  int n,x,t;
  cin>>n>>x>>t;
  
  int ans = n/x * t;
  ans += (n%x != 0)? t:0;
  cout<<ans<<endl;
  return 0;
}