#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  int N, Q;
  string S;
  cin >> N >> Q >> S;
  vector<int> V(N,0);
  for (int i=1; i<N; i++) {
    if (S[i-1]=='A' && S[i]=='C') {
      V[i]=V[i-1]+1;
    }
    else {
      V[i]=V[i-1];
    }
    //cout << V[i]<< endl;
  }
  int l, r;
  for (int i=0; i<Q; i++) {
    cin >> l >> r;
    l--;
    r--;
    cout << V[r]-V[l] << endl;
  }
}