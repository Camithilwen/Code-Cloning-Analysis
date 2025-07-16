#include <bits/stdc++.h>
using namespace std;

int main(){
string A,B,C;
  cin >> A >> B >> C;
  int D = A.size() - 1;
  int E = B.size() - 1;
  int F = C.size() - 1;
  if(A[D] == B[0] && B[E] == C[0]){
cout << "YES" << endl;
  }
else{
cout << "NO" << endl;
}
}
