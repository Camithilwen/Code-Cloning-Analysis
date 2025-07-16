#include <bits/stdc++.h>
using namespace std;
struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};
int main() {
  int N,K,L;cin>>N>>K>>L;
  UnionFind A(N);
  UnionFind B(N);
  for(int I=0;I<K;I++){
    int X,Y;cin>>X>>Y;X--;Y--;
    A.merge(X,Y);
  }
  for(int I=0;I<L;I++){
    int X,Y;cin>>X>>Y;X--;Y--;
    B.merge(X,Y);
  }
      map<pair<int,int>,int> ma;
    for (int v = 0; v < N; ++v) {
        pair<int,int> p(A.root(v), B.root(v));
        ma[p]++;
    }

    for (int v = 0; v < N; ++v) {
        pair<int,int> p(A.root(v), B.root(v));
        cout << ma[p] << " ";
    }
}
