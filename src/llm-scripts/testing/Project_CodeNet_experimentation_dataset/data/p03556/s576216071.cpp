#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;
  for (int i = N; i > 0; i--)
  {
    if (sqrt(i) == floor(sqrt(i))){
      cout << i << endl;
      return 0;
    }
 
  }
  
}