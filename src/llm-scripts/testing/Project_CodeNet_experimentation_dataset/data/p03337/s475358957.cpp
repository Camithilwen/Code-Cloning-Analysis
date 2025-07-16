#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){ 
  ll A,B;
  cin >> A >> B;
  
  if(max(A+B,A*B) > A-B) cout << max(A+B,A*B) << endl;
  else cout << A-B << endl;
}
