#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,char>;
using ll=long long;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), V(2, 0);
  
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  A.push_back(0);
  int s=1;
  for (int i=0; i<N; i++) {
    if (A[i]==A[i+1]) {
      s++;
    }
    else {
      int a=A[i];
      int n=s/2;
      //cout << N << endl;
      for (int j=0; j<n; j++) {
        V.push_back(a);
      }
      s=1;
    }
  }
  ll p=V[V.size()-1], q=V[V.size()-2];
  
  sort(V.begin(), V.end());
  cout << p*q << endl;
}
 