#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  vector<int>v(n);
  for (int i = 0; i < n; i++) {
    cin >> v.at(i);
  }
  
  vector<int>A(100000,0);
  for (int i = 0; i < n; i=i+2) {
    A.at(v.at(i)-1)++;
  }
  vector<int>a(100000,0);
   for (int i = 0; i < 100000; i++) {
    a.at(i) = A.at(i);
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  
  int F = -1;
  int S = -1;
  for (int i = 0; i < 100000; i++) {
    if (A.at(0) == a.at(i)){
      F = i+1;
    }
    else if (A.at(1) == a.at(i)){
      S = i+1;
    }
  }
    
  vector<int>B(100000,0);
  for (int i = 1; i < n; i=i+2) {
    B.at(v.at(i)-1)++;
  }
  vector<int>b(100000,0);
  for (int i = 0; i < 100000; i++) {
    b.at(i) = B.at(i);
  }
  sort(B.begin(), B.end());
  reverse(B.begin(), B.end());
  
  int f = -1;
  int s = -1;
  for (int i = 0; i < 100000; i++) {
    if (B.at(0) == b.at(i)){
      f = i+1;
    }
    else if (B.at(1) == b.at(i)){
      s = i+1;
    }
  }

  if (F == f){
    if (A.at(0)-A.at(1) > B.at(0)-B.at(1)){
      cout << n - A.at(0) - B.at(1) << endl;
    }
    else {
      cout << n - A.at(1) - B.at(0) << endl;
    }
  }
  else {
    cout << n - A.at(0) - B.at(0) << endl;
  }
}
    