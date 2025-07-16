#include <bits/stdc++.h>
using namespace std;

int main(){
  int P,Q,R;
  cin >> P >> Q >> R;
  int answer;
  answer = min(min(P+Q,Q+R),R+P);
  cout << answer << endl;
}
