#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin >> N; // 1 <= N <= 1+10^15 1000000000000001
  string abc = "abcdefghijklmnopqrstuvwxyz";
  string name = "";
  for(int i = 0; i < 11; i++){
    name = abc[(N-1)%26]+name;
    N = (N-1)/26;
    if(N == 0) break;
  }
  cout << name << endl;
}
