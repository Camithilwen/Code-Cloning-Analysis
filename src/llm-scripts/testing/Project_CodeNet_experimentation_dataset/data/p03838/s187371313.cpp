#include <bits/stdc++.h>
#include <vector>
#include <math.h>

using namespace std;
 int main(){

  long long  x,y;
  cin>>x>>y;


  if(x*y < 0) cout<<abs(abs(x) - abs(y))+1<<endl;
  else if(x*y == 0){

   if(x<y) cout<<y-x<<endl;
   else cout<<x-y+1<<endl;
  }
  else {
     if(x<y) cout<<y-x<<endl;
     else
        cout<<x-y+2<<endl;

  }


 return 0;
 }
