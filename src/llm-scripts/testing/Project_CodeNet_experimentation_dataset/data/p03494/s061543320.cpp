#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int result;
  result = 0;
  int resultnow;
  resultnow = 100;
  int a;
  for (int i = 0; i < n; i++)
  {
      cin >> a;
      result = 0;
      while (a%2==0)
      {
          a=a/2;
          result=result+1;
      }
      

      resultnow = min(result,resultnow);
       

          
  
      
  }
  cout << resultnow << endl;
  
}