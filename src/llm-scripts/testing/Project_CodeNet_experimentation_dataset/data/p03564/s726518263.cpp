#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n ;
  int result;
  result = 1;
  int k;
  cin >> k;
    for (int i = 0; i < n; i++)
    {
        if (result+k < result*2)
        {
            result = result + k;
        }
        else if (result*2 <= result+k)
        {
            result = result*2;
        }
        
        
    }
cout << result << endl;
  
  // ここにプログラムを追記

}