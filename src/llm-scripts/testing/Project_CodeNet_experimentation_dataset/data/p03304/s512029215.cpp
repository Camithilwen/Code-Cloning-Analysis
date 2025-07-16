#include <bits/stdc++.h>
using namespace std;

int main(){
  double n,m,d,ans;
  cin >> n >> m >> d;
  ans=0;
  if(d != 0){
    for(int i=0;i<m-1;i++){
      ans+=(2*(n-d))/(n*n);
    }
  }
  else{
   for(int i=0;i<m-1;i++){
      ans+=(n-d)/(n*n);
    }
  }
  cout<<fixed<<setprecision(20)<<ans<<endl;

  return 0;
}
