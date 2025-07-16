#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N,K,sum;
  sum = 0;
  cin >> N >> K;
vector<int> vec(N);
for (int i = 0; i < N; i++) {
  cin >> vec.at(i);
}
sort(vec.begin(), vec.end());
for (int i = 0; i < K; i++){
  sum += vec.at(N-1);
  N --;
}
  cout << sum << endl;
  
}