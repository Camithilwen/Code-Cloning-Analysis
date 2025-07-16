#include <bits/stdc++.h>

using namespace std;

int main(){

  int n, x;
  cin>>n>>x;
  
  long long int ans=0;
  long long int a;
  cin>>a;
  for(int i=0; i<n-1; i++){
    long long int b;
    long long int eat=0;
    cin>>b;
    
    eat=max(a+b-x, eat);
    ans+=eat;

    if(b<=eat) b=0;
    else b=b-eat;
    a=b;
  }

  cout<<ans<<endl;
}
