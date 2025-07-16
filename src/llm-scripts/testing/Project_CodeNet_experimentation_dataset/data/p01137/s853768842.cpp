#include <bits/stdc++.h>
#define int long long
using namespace std;
main(){
  int e;
  while(cin>>e,e){
    int ans=1e9;
    for(int z=0;;z++){
      if(z*z*z>e)break;
      for(int y=0;;y++){
        if(z*z*z+y*y>e)break;
        int a=e-z*z*z-y*y;
        ans=min(ans,a+y+z);
      }
    }
    cout<<ans<<endl;
  }
}

