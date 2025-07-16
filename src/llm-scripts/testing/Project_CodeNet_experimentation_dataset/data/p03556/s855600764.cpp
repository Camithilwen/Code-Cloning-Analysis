#include <bits/stdc++.h>
 using namespace std;
  int main(){
      int n;
      cin >> n;
      int ans=0;
      for(int i=n;i!=0;i--){
           int a=sqrt(i);
          if(a*a==i){
              ans=i;
              break;
          }
      }
      cout << ans << endl;
      
  }