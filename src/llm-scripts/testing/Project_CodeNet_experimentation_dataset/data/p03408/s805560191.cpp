#include <bits/stdc++.h>
using namespace std;

int main() {
  	
  int N;
  cin >> N;
  vector<string> s(N);
  for( int i = 0; i < N; i++ ) {
    cin >> s.at(i);
  }
  
  int M;
  cin >> M;
  vector<string> t(M);
  for( int i = 0; i < M; i++ ) {
    cin >> t.at(i);
  }
  
  
  vector<int> count(N);
  
  for ( int i = 0; i < N; i++ ) {
    for( int j = 0; j < N; j ++ ) {
        if (s.at(i) == s.at(j) ) {
          count.at(i)++;
        }
    }
    for ( int j = 0; j < M; j++ ) {
        if (s.at(i) == t.at(j) ) {
          count.at(i)--;
        }
      }
  }
  
  int max = 0;
  for( int i = 0; i < N; i++ ) {
    if( count.at(i) > max ) {
      max = count.at(i);
    }
  }
  
  cout << max << endl;
}