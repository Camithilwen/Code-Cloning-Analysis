#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  int x = 0;
  int y = 0;
  
  cin >> N;
  vector<string> blue(N);
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    blue.at(i) = s;
  }
  sort(blue.begin(), blue.end());
  reverse(blue.begin(), blue.end());
  
  cin >> M;
  vector<string> red(M);
  for (int i = 0; i < M; i++) {
    string t;
    cin >> t;
    red.at(i) = t;
  }
  sort(red.begin(), red.end());
  reverse(red.begin(), red.end());

  for (int j = 0; ; ) {
    if (N > 1 && M > 0) { 
      if (blue.at(N - 1) != red.at(M - 1)) {
        if (blue.at(N - 1) > red.at(M - 1)) {
          red.pop_back();
          M--;
        }
        else {
          if (blue.at(N - 1) == blue.at(N - 2)) { 
          blue.pop_back();
          N--;
          x++;
          }
          else {
            blue.pop_back();
            N--;
            x++;
            if (x > y) {
            y = x;
            }
            x = 0;
          }        
        }
      }
      
      else if (blue.at(N - 1) == red.at(M - 1)) { 
        if (blue.at(N - 1) == blue.at(N - 2)) {
          blue.pop_back();
          red.pop_back();
          N--;
          M--;
        }
        else {
          blue.pop_back();
          red.pop_back();
          N--;
          M--;
          if (x > y) {
            y = x;
          }
          x = 0;
        }
      }
    }
    
    else if (N > 1 && M == 0) 
      if (blue.at(N - 1) == blue.at(N - 2)) {
        blue.pop_back();
        N--;
        x++;
      }
      else {
        blue.pop_back();
        N--;
        x++;
          if (x > y) {
            y = x;
          }
        x = 0;
      }
    
    else if (N == 1 && M == 0) {
      x++;
      if (x > y) {
        y = x;
      }
      x = 0;
      break;
    }
    
    else if (N == 1 && M > 0) { 
      if (M > 1 && blue.at(N - 1) != red.at(M - 1)) {
        M--;
      }
      else if (M == 1 && blue.at(N - 1) != red.at(M - 1)) {
        x++;
        if (x > y) {
            y = x;
          }
        x = 0;
        break;
      }
      else if (blue.at(N - 1) == red.at(M - 1)) {
        if (x > y) {
          y = x;
          }
        x = 0;
        break;
      }
    }
  }
  cout << y << endl;
}