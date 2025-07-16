#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;

int main() {
  int N, doubt=0, M=0;
  cin >> N;
  vector<vector<pp>> V(N, vector<pp>(0));
  
  int A, p, q;
  
  for (int i=0; i<N; i++) {
    cin >> A;
    for (int j=0; j<A; j++) {
      cin >> p >> q;
      V[i].push_back(pp(p,q));
    }
  }
  
  for (int b=0; b<(1<<N); b++) {
    bitset<15> s(b);
    vector<int> W(N);
    doubt=0;
    
    for (int i=0; i<N; i++) {
      W[i]=s.test(i);
      //cout << W[i] << endl;
    }
    
    for (int i=0; i<N; i++) {
      if (s.test(i)) {
        for (int j=0; j<(int)V[i].size(); j++) {
          int x=V[i][j].first, y=V[i][j].second;
          if (W[x-1]!=y) {
            doubt=1;
            break;
          }
        }
        if (doubt==1) {break;}
      }
    }
    if (doubt==0) {
      int rr=0;
      for (int i=0; i<N; i++) {
        rr+=s.test(i);
      }
      M=max(M, rr);
      //cout << M << endl;
    }
  }
  cout << M << endl;
}