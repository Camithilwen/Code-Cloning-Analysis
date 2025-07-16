#include <bits/stdc++.h>
using namespace std;

int main()
{
   int N,Y,x,y,z;
   cin >> N >> Y;
   int check = 0;
   for(x=0;x<=N;x++){
      for(y = 0;y <=N;y++){
         z = N-x-y;
         if(z >= 0 && Y == 10000*x+5000*y+1000*z){
            check = 1;
            break;
         }
      }
      if(check)break;
   }
   if(check){
      cout << x << " " << y << " " << z << endl;
   }else{
      cout << -1 << " " << -1 << " " << -1 << endl;
   }
   

   return 0;
}
