#include<bits/stdc++.h>
using namespace std;

int main(void){
  string A, B, C;
  int cnt = 0;
  cin >> A;
  cin >> B;
  cin >> C;
  if(A[A.size() - 1] == B[0])
    cnt++;
  if(B[B.size() - 1] == C[0])
    cnt++;
  if(cnt == 2) cout << "YES" << "\n";
  else cout << "NO" << "\n";
  return 0;
}
