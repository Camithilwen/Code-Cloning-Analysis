#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int A, B, C;
  cin >> A >> B >> C;

  int K;
  cin >> K;

  int multi;
  for (int i = 0; i < K; i++)
  {
    multi = max(A, max(B, C)) * 2;
    if (A * 2 == multi) A = multi;
    else if (B * 2 == multi)
    {
      B = multi;
    }
    else
    {
      C = multi;
    }
    
    
  }
  
  cout << A + B + C << endl;
}