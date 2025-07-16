#include <bits/stdc++.h>
using namespace std;

int main() { int N, K;
  cin >> N >> K;
  int s = 1;

  for (int i = 0; i < N; i++){
      if(s<K){
        s = 2 * s;
      }
      else{
        s = s + K;
      }

  }
  cout << s << endl;

}
