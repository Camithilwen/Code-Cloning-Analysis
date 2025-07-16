#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;

  long long fb_sum = 0;

  for (int elem = 1; elem <= N; elem++){
    if (elem % 3 != 0 & elem % 5 != 0) fb_sum += elem;
  }

  cout << fb_sum << endl;
}