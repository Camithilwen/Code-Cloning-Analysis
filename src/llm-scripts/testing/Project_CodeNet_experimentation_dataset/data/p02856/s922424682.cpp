#include <bits/stdc++.h>
using namespace std;
int main(){
  int M;
  cin >> M;
  vector<int> d(M);
  vector<long long> c(M);
  for (int i = 0; i < M; i++){
    cin >> d[i] >> c[i];
  }
  long long cnt = 0;
  long long sum = 0;
  for (int i = 0; i < M; i++){
    cnt += c[i];
    sum += c[i] * d[i];
  }
  cout << cnt + (sum - 1) / 9 - 1 << endl;
}