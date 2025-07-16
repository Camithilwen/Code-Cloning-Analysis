#include <bits/stdc++.h>

using namespace std;

int main(){

  long long int n, a, b;
  cin>>n>>a>>b;

  long long int x[n]; 
  for(int i=0; i<n; i++) cin>>x[i];
  
  long long int walk_max=b/a;
  long long int tired=0;

  for(int i=0; i<n-1; i++){
    if(x[i+1]-x[i]>walk_max) tired+=b;
    else if(x[i+1]-x[i]<=walk_max){
      tired+=a*(x[i+1]-x[i]);
    }
  }

  cout<<tired<<endl;
}
