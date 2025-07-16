#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string S;
  cin >> S;
  int N = S.size();
  int sum = 0;
  vector<int> vec(N);
  rep(i, N) {
    if(S.at(i) == '0') {
      vec.at(i) = 0;
    }
    if(S.at(i) == '1') {
      vec.at(i) = 1;
    }
    if(S.at(i) == '2') {
      vec.at(i) = 2;
    }
    if(S.at(i) == '3') {
      vec.at(i) = 3;
    }
    if(S.at(i) == '4') {
      vec.at(i) = 4;
    }
    if(S.at(i) == '5') {
      vec.at(i) = 5;
    }
    if(S.at(i) == '6') {
      vec.at(i) = 6;
    }
    if(S.at(i) == '7') {
      vec.at(i) = 7;
    }
    if(S.at(i) == '8') {
      vec.at(i) = 8;
    }
    if(S.at(i) == '9') {
      vec.at(i) = 9;
    }
  }
  reverse(vec.begin(), vec.end());
  vector<int> vec10(N);
  rep(i, N) {
    if(i == 0) {
      vec10.at(i) = 1;
    }
    else {
      vec10.at(i) = vec10.at(i-1)*10;
    }
  }
  int sum2 = 0;
  rep(i, N) {
    sum += vec.at(i) * vec10.at(i);
    sum2 += vec.at(i);
  }
  if(sum%sum2 == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}